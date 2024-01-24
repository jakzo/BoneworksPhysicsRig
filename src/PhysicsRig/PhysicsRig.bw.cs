using System;
using System.Collections;
using System.Collections.Generic;
using StressLevelZero;
using StressLevelZero.Interaction;
using StressLevelZero.VRMK;
using StressLevelZero.Rig;
using UnityEngine;

namespace BoneworksMovement {
static class Layers {
  // public static int DEFAULT = LayerMask.NameToLayer("Default");
  public const int DEFAULT = 0; // must be constant to be used as default
  public static int PLAYER = LayerMask.NameToLayer("Player");
  public static int HAND = LayerMask.NameToLayer("Hand");
  public static int FEET = LayerMask.NameToLayer("Feet");
  public static int INTERACTABLE_ONLY =
      LayerMask.NameToLayer("InteractableOnly");
  public static int DYNAMIC = LayerMask.NameToLayer("Dynamic");
}

public class BwPhysicsRig : Rig {

  void Start() { CreateRigHierarchy(); }

  void Update() {}

  void CreateRigHierarchy() {
    foreach (var handedness in new[] { Handedness.LEFT, Handedness.RIGHT }) {
      var handednessText = handedness == Handedness.LEFT ? "left" : "right";
      var hand = CreateGameObject($"Hand ({handednessText})", parent: transform, layer: Layers.HAND, onCreated: obj => {
        // TODO: Rigidbody
        // TODO: BoxCollider
        // TODO: HandSFX
        // TODO: Hand
        // TODO: FingerCurl
        // TODO: PhysHand
        // TODO: ConfigurableJoint
        // TODO: InventorySlot
        // TODO: PlayerTriggerProxy
        // TODO: PlayerDamageReceiver
      });

      var palm = CreateGameObject(
          "PalmCenter", parent: hand.transform, layer: Layers.HAND
      );

      var fingers = CreateGameObject($"{handednessText[0]}_fingers_col", parent: hand.transform, layer: Layers.HAND, onCreated: obj => {
        // TODO: BoxCollider
      });

      var forearm = CreateGameObject($"{handednessText[0]}_foreArm_col", parent: hand.transform, layer: Layers.HAND, onCreated: obj => {
        // TODO: CapsuleCollider
      });

      var inventoryCapsule =
          CreateGameObject("Inventory", parent: hand.transform, layer: Layers.INTERACTABLE_ONLY, onCreated: obj => {
            // TODO: CapsuleCollider
          });

      var inventorySphere =
          CreateGameObject("Inventory", parent: hand.transform, layer: Layers.INTERACTABLE_ONLY, onCreated: obj => {
            // TODO: SphereCollider
          });
    }

    var pelvis =
        CreateGameObject("Pelvis", parent: transform, layer: Layers.DEFAULT, onCreated: obj => {
          // TODO: Rigidbody
          // TODO: PhysBody
          // TODO: PlayerDamageReceiver
          // TODO: PlayerTriggerProxy

          var chest =
              CreateGameObject("Chest", parent: transform, layer: Layers.PLAYER, onCreated: obj2 => {
                // TODO: CapsuleCollider
                // TODO: BoxCollider

                var trigger = CreateGameObject(
                    "ChestTriggerProxy", parent: transform, layer: Layers.PLAYER
                );
              });

          var collider =
              CreateGameObject("pelvisCol", parent: transform, layer: Layers.PLAYER, onCreated: obj2 => {
                // TODO: CapsuleCollider
              });

          var resetHandLeft = CreateGameObject(
              "Reset Hand (left)", parent: transform, layer: Layers.DEFAULT
          );
          var resetHandRight = CreateGameObject(
              "Reset Hand (right)", parent: transform, layer: Layers.DEFAULT
          );
        });

    var
        knee =
            CreateGameObject("Knee", parent: transform, layer: Layers.FEET, onCreated: obj => {
              // TODO: SphereCollider
              // TODO: Rigidbody
              // TODO: ConfigurableJoint
              // TODO: PlayerTriggerProxy
              // TODO: PlayerDamageReceiver

              var kneeToPelvis = CreateGameObject("KneeToPelvis", parent: transform, layer: Layers.FEET, onCreated: obj2 => {
        // TODO: CapsuleCollider
      });
            });

    var feet =
        CreateGameObject("Feet", parent: transform, layer: Layers.FEET, onCreated: obj => {
          // TODO: SphereCollider
          // TODO: Rigidbody
          // TODO: ConfigurableJoint
          // TODO: PhysGrounder
          // TODO: PlayerTriggerProxy
          // TODO: PlayerDamageReceiver
        });

    foreach (var handedness in new[] { Handedness.RIGHT, Handedness.LEFT }) {
      var handednessText = handedness == Handedness.LEFT ? "left" : "right";
      var foot = CreateGameObject(
          $"Foot ({handednessText})", parent: transform, layer: Layers.DYNAMIC
      );
    }
  }

  GameObject CreateGameObject(
      string name, Transform parent = null, int layer = Layers.DEFAULT,
      Action<GameObject> onCreated = null
  ) {
    var obj = new GameObject(name) { layer = layer };
    obj.transform.SetParent(parent, false);
    onCreated?.Invoke(obj);
    return obj;
  }

  // ---

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
    // TODO
  }

  public void OnStart() {
    // TODO
  }

  public void OnUpdate() {
    // TODO
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
    // TODO
  }

  public void DisableBallLoco() {
    // TODO
  }

  public BwPhysicsRig() {
    // TODO
  }
}
}
