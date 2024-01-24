using System;
using System.Collections;
using System.Collections.Generic;
using StressLevelZero;
using StressLevelZero.Interaction;
using StressLevelZero.VRMK;
using StressLevelZero.Rig;
using UnityEngine;

namespace BoneworksMovement {
public class BwPhysHand : MonoBehaviour {
  public Rigidbody rb;
  public ConfigurableJoint bodyJ;
  public PhysBody physBody;
  public PhysHand otherHand;
  public float dampening;
  public float newtonDamp;
  public float additionalMass;
  public float forceMultiplier;
  public float xPosForce;
  public float xNegForce;
  public float yPosForce;
  public float yNegForce;
  public float zPosForce;
  public float zNegForce;
  public float maxTorque;
  public float angDampening;
  public float gripMult;
  private float _jerkedMult;
  private float angJerkMult;
  private float _xPos;
  private float _xNeg;
  private float _yPos;
  private float _yNeg;
  private float _zPos;
  private float _zNeg;
  private Quaternion _muscleSpace;
  private Quaternion _initialHandRot;
  public AnimationCurve TorqueMultiplier;
  public Collider forearmCol;
  private Vector3 _lastTargetLocalPos;
  private Quaternion _lastTargetRotation;
  public Transform t1Vert;
  public Transform shoulder;
  public Transform wrist;
  private float _armlength;
  private float _stuck;
  private Vector3 _lastForce;
  private Vector3 _lastVel;
  private Vector3 _lastTorque;
  private Vector3 _lastAngVel;
  private bool _colliding;
  private int _forearmCollidingCount;
  private Vector3 _forearmCollisionPoint;
  private Vector3 _forearmCollisionNormal;
  private Vector3 _collisionImpulse;
  public Vector3 currentCollision;
  public Vector3 appliedForce;
  public Vector3 appliedTorque;
  public float handSupported;
  private bool _isHighFriction;
  private PhysicMaterial _highFriction;
  public PhysicMaterial lowFriction;
  public Collider[] handColliders;
  public Vector3 rbOffset;
  public bool drawMaxForceDebug;
  public bool drawAccuracyDebug;
  public bool forceViaJoint;
  public PhysHand.HandPhysState handPhysState;

  private void Awake() {
    // TODO
  }

  public void UpdateHand(
      Vector3 targetLocalPos, Quaternion targetRotation, float armlength,
      ConfigurableJoint joint, Vector3 shoulderWorld, float bodyDominance,
      float gripInput
  ) {
    // TODO
  }

  private void
  ApplyForce(Vector3 targetLocalPos, ConfigurableJoint joint, float bodyDom) {
    // TODO
  }

  private void PrepShoulderMuscle(Vector3 handVelocity, Vector3 newtonsDamped) {
    // TODO
  }

  private Vector3 MuscleClamp(Vector3 desiredForce) {
    // TODO
  }

  private Vector3 MuscleMax(Vector3 direction) {
    // TODO
  }

  private void SetFriction(float grip) {
    // TODO
  }

  private float RelaxTorqueMult(float grip) {
    // TODO
  }

  private void ApplyTorque(
      Quaternion targetRotation, float maxTor, ConfigurableJoint joint
  ) {
    // TODO
  }

  public bool
  RefreshHandStates(ConfigurableJoint thisJ, ConfigurableJoint otherJ) {
    // TODO
  }

  public static Vector3 Div(Vector3 v, Vector3 v2) {
    // TODO
  }

  private bool IsNanV3(Vector3 v) {
    // TODO
  }

  private Vector3 AbsV3(Vector3 v) {
    // TODO
  }

  public void SetHand(
      Vector3 worldPosition, Quaternion worldRotation, bool zeroVelocity = true
  ) {
    // TODO
  }

  public void ClearJerk() {
    // TODO
  }

  public void CollisionRelay(Collision c) {
    // TODO
  }

  public bool ReadAndClearForearmCollision(
      out Vector3 worldPosition, out Vector3 worldNormal
  ) {
    // TODO
  }

  public void ReadSensors(ConfigurableJoint joint, ref float divByNewtons) {
    var jointForceY = _collisionImpulse.y;
    if (joint) {
      var isHandStateStatic =
          handPhysState == PhysHand.HandPhysState.StaticOneHand ||
          handPhysState == PhysHand.HandPhysState.StaticTwoHand;
      var exertedForceY =
          isHandStateStatic ? Math.Abs(appliedForce.y) : joint.currentForce.y;
      jointForceY += Time.fixedDeltaTime * exertedForceY;
    }

    var handSpeed = Time.fixedDeltaTime *
        (jointForceY * divByNewtons <= handSupported ? 4f : 8f);

    handSupported =
        Mathf.MoveTowards(handSupported, jointForceY * divByNewtons, handSpeed);

    CheckStuck(divByNewtons);
  }

  public float ArmMantle() {
    // TODO
  }

  public bool CheckStuck(float divByNewtons) {
    // TODO
  }

  public BwPhysHand() {
    // TODO
  }
}
}
