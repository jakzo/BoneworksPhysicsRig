using System;
using System.Collections;
using System.Collections.Generic;
using StressLevelZero;
using StressLevelZero.Interaction;
using StressLevelZero.VRMK;
using StressLevelZero.Rig;
using UnityEngine;

namespace BoneworksMovement {
public class BwPhysicsRig : Rig {
  public Hand leftHand;
  public Hand rightHand;
  public Transform leftHandResetTransform;
  public Transform rightHandResetTransform;
  public PhysBody physBody;
  private Vector3 _lastHeadPos;
  private Coroutine resetHandsCoroutine;
  private Vector3 _avgVel;
  private Quaternion _initialPelvisRotation;
  private bool _ballLocoEnabled;

  public Vector3 pelvisVelocity { get; set; }
  public Vector3 groundVelocity { get; set; }
  public Vector3 pelvisAccel { get; set; }
  public Vector3 headDelta { get; set; }

  private IEnumerator CoResetHand(Handedness handedness) {
    // TODO
    yield return null;
  }

  public void OnAwake() {
    leftHand = m_leftHand.GetComponent<Hand>();
    leftHand.SetManger(manager);
    rightHand = m_rightHand.GetComponent<Hand>();
    rightHand.SetManger(manager);

    physBody = GetComponentInChildren<PhysBody>();
    physBody.OnAwake();

    _initialPelvisRotation = physBody.rbPelvis.rotation;
    _ballLocoEnabled = true;
  }

  public void OnStart() {
    var bodyRefs = manager.gameWorldSkeletonRig.body.references;

    leftHand.physHand.t1Vert = bodyRefs.c4Vertebra;
    leftHand.physHand.shoulder = bodyRefs.rtScapula;
    // TODO: Why elbow?
    leftHand.physHand.wrist = bodyRefs.rightElbow;

    leftHand.physHand.t1Vert = bodyRefs.c4Vertebra;
    leftHand.physHand.shoulder = bodyRefs.leftShoulder;
    leftHand.physHand.wrist = bodyRefs.leftWrist;

    var prevRig =
        manager.rigs[(rigIndex == 0 ? manager.rigs.Length : rigIndex) - 1];
    leftHand.physHand.SetHand(
        prevRig.m_leftHand.position, prevRig.m_leftHand.rotation, true
    );
    rightHand.physHand.SetHand(
        prevRig.m_rightHand.position, prevRig.m_rightHand.rotation, true
    );

    physBody.OnStart();
  }

  public void OnUpdate() {
    var footFloorPos =
        physBody.rbFeet.position - new Vector3(0f, physBody.footballRadius, 0f);
    manager.gameWorldSkeletonRig.transform.SetPositionAndRotation(
        footFloorPos, manager.realtimeSkeletonRig.transform.rotation
    );

    Physics.SyncTransforms();

    leftHand.OrderedUpdate();
    rightHand.OrderedUpdate();

    var bodyRefs = manager.realtimeSkeletonRig.body.references;
    physBody.UpdateColliders(
        leftHand.controller.GetSecondaryInteractionButtonAxis(),
        rightHand.controller.GetSecondaryInteractionButtonAxis(), ref bodyRefs
    );
  }

  public void OnFixedUpdate() {
    _lastHeadPos = m_head.position;
    var prevRig =
        manager.rigs[(rigIndex == 0 ? manager.rigs.Length : rigIndex) - 1];
    var nearPelvisLocalPos = new Vector3(0f, m_pelvis.localPosition.y, -0.04f);
    var nearPelvisPos = prevRig.transform.TransformPoint(nearPelvisLocalPos);
    // TODO: Is this position the base of the neck? (check in game)
    var targetHeadPos = m_pelvis.position + (m_head.position - nearPelvisPos);
    var pelvisAtHeadHeightLocalPos =
        m_pelvis.InverseTransformPoint(targetHeadPos);
    physBody.headJoint.connectedAnchor = pelvisAtHeadHeightLocalPos;
    physBody.headJoint.targetRotation =
        Quaternion.Inverse(m_head.rotation) * _initialPelvisRotation;

    Grip leftGrip = null;
    Grip rightGrip = null;
    var leftGripBodyDominance = leftHand.attachedInteractable != null &&
            Grip.Cache.TryGet(
                leftHand.attachedInteractable.gameObject, out leftGrip
            )
        ? leftGrip.bodyDominance
        : 1.0f;
    var rightGripBodyDominance = rightHand.attachedInteractable != null &&
            Grip.Cache.TryGet(
                rightHand.attachedInteractable.gameObject, out rightGrip
            )
        ? rightGrip.bodyDominance
        : 1.0f;

    // TODO: Is this what the result means?
    var isHandsRefreshed =
        leftHand.physHand.RefreshHandStates(leftHand.joint, rightHand.joint);
    var leftHandPos = m_leftHand.position;
    var rightHandPos = m_rightHand.position;
    if (isHandsRefreshed && !leftGrip.HasVirtualController) {
      StaticVirtualController(
          leftGrip, rightGrip, ref leftHandPos, ref rightHandPos
      );
      m_leftHand.position = leftHandPos;
      m_rightHand.position = rightHandPos;
    }

    // TODO: Why does one hand use rtScapula and the other leftShoulder?
    leftHand.physHand.UpdateHand(
        leftHandPos - nearPelvisPos, m_leftHand.rotation,
        manager.gameWorldSkeletonRig.body.armLength, leftHand.joint,
        manager.realtimeSkeletonRig.body.references.rtScapula.position,
        leftGripBodyDominance,
        leftHand.controller.GetSecondaryInteractionButtonAxis()
    );
    rightHand.physHand.UpdateHand(
        rightHandPos - nearPelvisPos, m_rightHand.rotation,
        manager.gameWorldSkeletonRig.body.armLength, rightHand.joint,
        manager.realtimeSkeletonRig.body.references.leftShoulder.position,
        rightGripBodyDominance,
        rightHand.controller.GetSecondaryInteractionButtonAxis()
    );

    leftHand.OrderedFixedUpdate();
    rightHand.OrderedFixedUpdate();

    physBody.rbPelvis.transform.localRotation = Quaternion.identity;
    physBody.rbKnee.transform.localRotation = Quaternion.identity;

    if (_ballLocoEnabled) {
      physBody.SetBodyMassDistribution();
      physBody.UpdateKnee(m_pelvis.localPosition.z);
      physBody.ApplyForce(
          (m_head.position - targetHeadPos) / Time.fixedDeltaTime
      );
    }
  }

  public void OnAfterFixedUpdate() {
    var gravityForce =
        1f / (Time.fixedDeltaTime * Mathf.Abs(Physics.gravity.y) * 82f);
    leftHand.physHand.ReadSensors(leftHand.joint, ref gravityForce);
    rightHand.physHand.ReadSensors(rightHand.joint, ref gravityForce);
    // TODO
  }

  private void StaticVirtualController(
      Grip leftGrip, Grip rightGrip, ref Vector3 lfHand, ref Vector3 rtHand
  ) {
    // TODO
  }

  public void Teleport(Vector3 displace, bool zeroVelocity = false) {
    // TODO
  }

  public void EnableBallLoco() {
    physBody.rbFeet.detectCollisions = true;
    physBody.rbKnee.detectCollisions = true;
    physBody.footballRadius = 0.18f;
    physBody.bodyMassNaturalHold = false;
    physBody.SetBodyMassDistribution();
  }

  public void DisableBallLoco() {
    physBody.rbFeet.detectCollisions = false;
    physBody.rbKnee.detectCollisions = false;
    physBody.footballRadius = 0.11f;
    physBody.bodyMassNaturalHold = true;
    physBody.SetBodyMassDistribution();
    physBody.UpdateKnee(0f);
  }
}
}
