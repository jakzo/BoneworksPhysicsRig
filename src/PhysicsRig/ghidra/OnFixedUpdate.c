
/* WARNING: Unable to use type for symbol tempVec1XY */

void StressLevelZero_Rig_PhysicsRig__OnFixedUpdate
               (StressLevelZero_Rig_PhysicsRig_o *__this,MethodInfo *method)

{
  float armlength;
  UnityEngine_ConfigurableJoint_o *joint;
  bool hasLeftGrip;
  uint prevRigIdx;
  UnityEngine_Vector3_o *headPos;
  UnityEngine_Transform_o *prevRigTransform;
  UnityEngine_Vector3_o *pelvisLocalPos;
  UnityEngine_Vector3_o *nearPelvisWorldPos_;
  UnityEngine_Vector3_o *pelvisPos;
  UnityEngine_Vector3_o *headPos2;
  UnityEngine_Vector3_o *pelvisToHead;
  UnityEngine_Vector3_o *pelvisAtHeadHeight;
  UnityEngine_Vector3_o *pelvisAtHeadHeightLocalPos;
  UnityEngine_Quaternion_o *headRot;
  UnityEngine_Quaternion_o *headRotInverse;
  UnityEngine_Quaternion_o *initialHeadRotInverse;
  StressLevelZero_Interaction_Interactable_o *leftAttachedInteractable;
  bool isLeftHandHolding;
  Utilties_ComponentCache_Grip__o *gripCache;
  StressLevelZero_Interaction_Interactable_o *leftAttachedInteractable2;
  UnityEngine_GameObject_o *gameObject;
  bool hasRightGrip;
  bool refreshHandStateResult;
  StressLevelZero_Interaction_Interactable_o *rightAttachedInteractable;
  bool isRightHandHolding;
  Utilties_ComponentCache_Grip__o *gripCache2;
  StressLevelZero_Interaction_Interactable_o *rightAttachedInteractable2;
  UnityEngine_GameObject_o *gameObject2;
  UnityEngine_Vector3_o *leftHandPos;
  UnityEngine_Vector3_o *rightHandPos;
  bool leftGripHasVirtualController;
  StressLevelZero_VRMK_SLZ_Body_o *gameSkelBody;
  StressLevelZero_VRMK_SLZ_Body_o *realSkelBody;
  UnityEngine_Vector3_o *pelvisToLeftHand;
  UnityEngine_Quaternion_o *leftHandRot;
  UnityEngine_Vector3_o *rtScapulaPos;
  StressLevelZero_Rig_BaseController_o *leftController;
  UnityEngine_Vector3_o *pelvisToRightHand;
  UnityEngine_Quaternion_o *rightHandRot;
  UnityEngine_Vector3_o *leftShoulderPos;
  StressLevelZero_Rig_BaseController_o *rightController;
  UnityEngine_Rigidbody_o *rbPelvis;
  UnityEngine_Transform_o *pelvisTransform;
  UnityEngine_Quaternion_o *quaternionIdentity;
  UnityEngine_Rigidbody_o *rbKnee;
  UnityEngine_Transform_o *kneeTransform;
  UnityEngine_Quaternion_o *quaternionIdentity2;
  UnityEngine_Vector3_o *pelvisLocalPos2;
  UnityEngine_Vector3_o *headPos3;
  UnityEngine_Vector3_o *neckBaseToHead;
  UnityEngine_Vector3_o *targetHeadPos;
  longlong ex;
  float rightHandZ;
  float leftHandZ;
  float leftGripButton_;
  float gripInput;
  float fixedDeltaTime;
  float leftHandX;
  float leftHandY;
  float rightHandX;
  float rightHandY;
  float rightGripBodyDominance;
  float leftGripBodyDominance;
  StressLevelZero_Interaction_Grip_o *leftGrip;
  StressLevelZero_Interaction_Grip_o *rightGrip;
  UnityEngine_Vector3_o nearPelvisLocalPos_;
  UnityEngine_Quaternion_o tempVecOrQuat3;
  UnityEngine_Quaternion_o tempVecOrQuat2;
  UnityEngine_Quaternion_o tempVecOrQuat1;
  UnityEngine_Transform_o *m_head;
  undefined8 tempVec1XY;
  UnityEngine_Transform_o *m_pelvis2;
  float headY;
  UnityEngine_Transform_o *m_pelvis;
  UnityEngine_Transform_o *m_pelvis3;
  StressLevelZero_VRMK_PhysBody_o *physBody;
  UnityEngine_Transform_o *m_head3;
  UnityEngine_ConfigurableJoint_o *headJoint2;
  StressLevelZero_VRMK_PhysBody_o *physBody2;
  UnityEngine_Transform_o *m_head2;
  StressLevelZero_Interaction_Hand_o *leftHand2;
  StressLevelZero_Interaction_Hand_o *rightHand;
  float headRotZ;
  StressLevelZero_Interaction_Hand_o *leftHand;
  StressLevelZero_VRMK_PhysHand_o *leftPhysHand;
  StressLevelZero_Interaction_Hand_o *leftHand3;
  StressLevelZero_Interaction_Hand_o *rightHand3;
  UnityEngine_Transform_o *rightHand4;
  UnityEngine_Transform_o *leftHand4;
  StressLevelZero_Interaction_Hand_o *rightHand2;
  UnityEngine_Transform_o *rightHand5;
  StressLevelZero_Rig_SkeletonRig_o *gameWorldSkelRig;
  StressLevelZero_Interaction_Hand_o *leftHand6;
  StressLevelZero_VRMK_PhysHand_o *leftPhysHand2;
  UnityEngine_Transform_o *leftHand5;
  UnityEngine_Transform_o *rtScapula;
  StressLevelZero_Interaction_Hand_o *leftHand7;
  UnityEngine_ConfigurableJoint_o *leftHandJoint;
  float rtScapulaZ;
  StressLevelZero_Interaction_Hand_o *leftHand8;
  float pelvisToLeftHandZ;
  UnityEngine_Transform_o *m_leftHand3;
  float leftHandRotZ;
  float leftHandRotW;
  StressLevelZero_Interaction_Hand_o *rightHand7;
  UnityEngine_Transform_o *leftShoulder;
  StressLevelZero_Interaction_Hand_o *rightHand8;
  StressLevelZero_Interaction_Hand_o *rightHand6;
  UnityEngine_Transform_o *m_rightHand;
  StressLevelZero_VRMK_PhysBody_o *physBody5;
  UnityEngine_Transform_o *m_pelvis4;
  StressLevelZero_VRMK_PhysBody_o *physBody6;
  StressLevelZero_VRMK_PhysBody_o *physBody3;
  StressLevelZero_Interaction_Hand_o *leftHand9;
  StressLevelZero_VRMK_PhysBody_o *physBody4;
  UnityEngine_Joint_o *headJoint;
  undefined8 headRotXY;
  undefined8 headXY;
  undefined8 leftHandRotXY;
  undefined8 leftShoulderXY;
  float leftShoulderZ;
  UnityEngine_Transform_o *m_head4;
  undefined8 neckBaseToHeadXY;
  undefined8 pelvisToLeftHandXY;
  undefined8 pelvisToRightHandXY;
  StressLevelZero_VRMK_PhysBody_o *physBody7;
  StressLevelZero_Rig_Rig_o *prevRig;
  StressLevelZero_VRMK_SLZ_Body_References_o *realSkelBodyRefs;
  StressLevelZero_Rig_SkeletonRig_o *realtimeSkelRig;
  StressLevelZero_Rig_RigManager_o *rigManager;
  StressLevelZero_Interaction_Hand_o *rightHand9;
  float rightHandRotW;
  undefined8 rightHandRotXY;
  float rightHandRotZ;
  StressLevelZero_VRMK_PhysHand_o *rightPhysHand;
  StressLevelZero_Rig_Rig_array *rigs;
  undefined8 rtScapulaXY;
  float tempVec1Z;
  undefined8 tempVec22XY;
  undefined8 tempVec2XY;
  float tempVec2Z;
  
  if (DAT_181ebb17a == '\0') {
    FUN_1801ad630(0x6024);
    DAT_181ebb17a = '\x01';
  }
  rigManager = (__this->fields).field0_0x0.manager;
  leftGrip = (StressLevelZero_Interaction_Grip_o *)0x0;
  rightGrip = (StressLevelZero_Interaction_Grip_o *)0x0;
  if ((rigManager == (StressLevelZero_Rig_RigManager_o *)0x0) ||
     (rigs = (rigManager->fields).rigs, rigs == (StressLevelZero_Rig_Rig_array *)0x0)) {
ThrowNullReferenceException:
                    /* WARNING: Subroutine does not return */
    ThrowNullReferenceException();
  }
  prevRigIdx = StressLevelZero_Utils__Mod
                         ((__this->fields).field0_0x0.rigIndex + -1,*(int32_t *)&rigs->max_length,
                          (MethodInfo *)0x0);
  if (*(uint *)&rigs->max_length <= prevRigIdx) {
    ex = IndexOutOfRangeException();
                    /* WARNING: Subroutine does not return */
    ThrowException(ex);
  }
  m_head = (__this->fields).field0_0x0.m_head;
  prevRig = rigs->m_Items[(int)prevRigIdx];
  if (m_head == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  headPos = UnityEngine_Transform__get_position
                      ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_head,(MethodInfo *)0x0);
  headY = (headPos->fields).y;
  (__this->fields)._lastHeadPos.fields.x = (headPos->fields).x;
  (__this->fields)._lastHeadPos.fields.y = headY;
  (__this->fields)._lastHeadPos.fields.z = (headPos->fields).z;
  if (prevRig == (StressLevelZero_Rig_Rig_o *)0x0) goto ThrowNullReferenceException;
  prevRigTransform =
       UnityEngine_Component__get_transform((UnityEngine_Component_o *)prevRig,(MethodInfo *)0x0);
  m_pelvis = (prevRig->fields).m_pelvis;
  if (m_pelvis == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  pelvisLocalPos =
       UnityEngine_Transform__get_localPosition
                 ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_pelvis,(MethodInfo *)0x0);
  tempVecOrQuat1.fields.x = (pelvisLocalPos->fields).x;
  tempVecOrQuat1.fields.y = (pelvisLocalPos->fields).y;
  tempVecOrQuat1.fields.z = (pelvisLocalPos->fields).z;
  nearPelvisLocalPos_.fields.x = 0.0;
  nearPelvisLocalPos_.fields.y = 0.0;
  nearPelvisLocalPos_.fields.z = 0.0;
  UnityEngine_Vector3__Set(&nearPelvisLocalPos_,0.0,SUB84(tempVecOrQuat1.fields._0_8_,4),-0.04);
  if (prevRigTransform == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  tempVecOrQuat2.fields.x = nearPelvisLocalPos_.fields.x;
  tempVecOrQuat2.fields.y = nearPelvisLocalPos_.fields.y;
  tempVecOrQuat2.fields.z = nearPelvisLocalPos_.fields.z;
  nearPelvisWorldPos_ =
       UnityEngine_Transform__TransformPoint
                 ((UnityEngine_Vector3_o *)&tempVecOrQuat1,prevRigTransform,
                  (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
  m_pelvis2 = (__this->fields).field0_0x0.m_pelvis;
  tempVec1Z = (nearPelvisWorldPos_->fields).z;
  tempVec1XY._0_4_ = (nearPelvisWorldPos_->fields).x;
  tempVec1XY._4_4_ = (nearPelvisWorldPos_->fields).y;
  if (m_pelvis2 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  pelvisPos = UnityEngine_Transform__get_position
                        ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_pelvis2,(MethodInfo *)0x0);
  m_head2 = (prevRig->fields).m_head;
  tempVec2XY._0_4_ = (pelvisPos->fields).x;
  tempVec2XY._4_4_ = (pelvisPos->fields).y;
  tempVec2Z = (pelvisPos->fields).z;
  if (m_head2 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  headPos2 = UnityEngine_Transform__get_position
                       ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_head2,(MethodInfo *)0x0);
  tempVecOrQuat3.fields.x = (headPos2->fields).x;
  tempVecOrQuat3.fields.y = (headPos2->fields).y;
  tempVecOrQuat3.fields.z = (headPos2->fields).z;
  if (((*(byte *)(UnityEngine_Vector3_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine_Vector3_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  tempVecOrQuat2.fields._0_8_ = tempVec1XY;
  tempVecOrQuat2.fields.z = tempVec1Z;
  pelvisToHead = UnityEngine_Vector3__op_Subtraction
                           ((UnityEngine_Vector3_o *)&tempVecOrQuat1,
                            (UnityEngine_Vector3_o *)&tempVecOrQuat3,
                            (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
  tempVecOrQuat2.fields.x = (pelvisToHead->fields).x;
  tempVecOrQuat2.fields.y = (pelvisToHead->fields).y;
  tempVecOrQuat2.fields.z = (pelvisToHead->fields).z;
  tempVecOrQuat3.fields._0_8_ = tempVec2XY;
  tempVecOrQuat3.fields.z = tempVec2Z;
  pelvisAtHeadHeight =
       UnityEngine_Vector3__op_Addition
                 ((UnityEngine_Vector3_o *)&tempVecOrQuat1,(UnityEngine_Vector3_o *)&tempVecOrQuat3,
                  (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
  physBody = (__this->fields).physBody;
  tempVec2Z = (pelvisAtHeadHeight->fields).z;
  tempVec22XY._0_4_ = (pelvisAtHeadHeight->fields).x;
  tempVec22XY._4_4_ = (pelvisAtHeadHeight->fields).y;
  if (physBody == (StressLevelZero_VRMK_PhysBody_o *)0x0) goto ThrowNullReferenceException;
  m_pelvis3 = (__this->fields).field0_0x0.m_pelvis;
  headJoint = (UnityEngine_Joint_o *)(physBody->fields).headJoint;
  if ((m_pelvis3 == (UnityEngine_Transform_o *)0x0) ||
     (tempVecOrQuat2.fields._0_8_ = tempVec22XY, tempVecOrQuat2.fields.z = tempVec2Z,
     pelvisAtHeadHeightLocalPos =
          UnityEngine_Transform__InverseTransformPoint
                    ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_pelvis3,
                     (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0),
     headJoint == (UnityEngine_Joint_o *)0x0)) goto ThrowNullReferenceException;
  tempVecOrQuat2.fields.x = (pelvisAtHeadHeightLocalPos->fields).x;
  tempVecOrQuat2.fields.y = (pelvisAtHeadHeightLocalPos->fields).y;
  tempVecOrQuat2.fields.z = (pelvisAtHeadHeightLocalPos->fields).z;
  UnityEngine_Joint__set_connectedAnchor
            (headJoint,(UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
  physBody2 = (__this->fields).physBody;
  if (physBody2 == (StressLevelZero_VRMK_PhysBody_o *)0x0) goto ThrowNullReferenceException;
  m_head3 = (prevRig->fields).m_head;
  headJoint2 = (physBody2->fields).headJoint;
  if (m_head3 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  headRot = UnityEngine_Transform__get_rotation(&tempVecOrQuat1,m_head3,(MethodInfo *)0x0);
  headRotXY._0_4_ = (headRot->fields).x;
  headRotXY._4_4_ = (headRot->fields).y;
  headRotZ = (headRot->fields).z;
  tempVecOrQuat1.fields.w = (headRot->fields).w;
  if (((*(byte *)(UnityEngine_Quaternion_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine_Quaternion_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  tempVecOrQuat1.fields._0_8_ = headRotXY;
  tempVecOrQuat1.fields.z = headRotZ;
  headRotInverse =
       UnityEngine_Quaternion__Inverse(&tempVecOrQuat2,&tempVecOrQuat1,(MethodInfo *)0x0);
  tempVecOrQuat1.fields.x = (__this->fields)._initialPelvisRotation.fields.x;
  tempVecOrQuat1.fields.y = (__this->fields)._initialPelvisRotation.fields.y;
  tempVecOrQuat1.fields.z = (__this->fields)._initialPelvisRotation.fields.z;
  tempVecOrQuat1.fields.w = (__this->fields)._initialPelvisRotation.fields.w;
  tempVecOrQuat2.fields.x = (headRotInverse->fields).x;
  tempVecOrQuat2.fields.y = (headRotInverse->fields).y;
  tempVecOrQuat2.fields.z = (headRotInverse->fields).z;
  tempVecOrQuat2.fields.w = (headRotInverse->fields).w;
  initialHeadRotInverse =
       UnityEngine_Quaternion__op_Multiply
                 (&tempVecOrQuat3,&tempVecOrQuat2,&tempVecOrQuat1,(MethodInfo *)0x0);
  if (headJoint2 == (UnityEngine_ConfigurableJoint_o *)0x0) goto ThrowNullReferenceException;
  tempVecOrQuat1.fields.x = (initialHeadRotInverse->fields).x;
  tempVecOrQuat1.fields.y = (initialHeadRotInverse->fields).y;
  tempVecOrQuat1.fields.z = (initialHeadRotInverse->fields).z;
  tempVecOrQuat1.fields.w = (initialHeadRotInverse->fields).w;
  UnityEngine_ConfigurableJoint__set_targetRotation(headJoint2,&tempVecOrQuat1,(MethodInfo *)0x0);
  leftHand = (__this->fields).leftHand;
  rightGripBodyDominance = 1.0;
  leftGripBodyDominance = 1.0;
  if (leftHand == (StressLevelZero_Interaction_Hand_o *)0x0) goto ThrowNullReferenceException;
  leftAttachedInteractable =
       StressLevelZero_Interaction_Hand__get_attachedInteractable(leftHand,(MethodInfo *)0x0);
  if (((*(byte *)(UnityEngine_Object_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine_Object_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  isLeftHandHolding =
       UnityEngine_Object__op_Inequality
                 ((UnityEngine_Object_o *)leftAttachedInteractable,(UnityEngine_Object_o *)0x0,
                  (MethodInfo *)0x0);
  if (isLeftHandHolding) {
    gripCache = StressLevelZero_Interaction_Grip__get_Cache((MethodInfo *)0x0);
    leftHand2 = (__this->fields).leftHand;
    if (((leftHand2 == (StressLevelZero_Interaction_Hand_o *)0x0) ||
        (leftAttachedInteractable2 =
              StressLevelZero_Interaction_Hand__get_attachedInteractable
                        (leftHand2,(MethodInfo *)0x0),
        leftAttachedInteractable2 == (StressLevelZero_Interaction_Interactable_o *)0x0)) ||
       (gameObject = UnityEngine_Component__get_gameObject
                               ((UnityEngine_Component_o *)leftAttachedInteractable2,
                                (MethodInfo *)0x0),
       gripCache == (Utilties_ComponentCache_Grip__o *)0x0)) goto ThrowNullReferenceException;
    hasLeftGrip = Utilties_ComponentCache<object>__TryGet
                            ((Utilties_ComponentCache_object__o *)gripCache,gameObject,
                             (Il2CppObject **)&leftGrip,
                             Method_Utilties_ComponentCache<Grip>_TryGet__);
    if (hasLeftGrip) {
      if (leftGrip == (StressLevelZero_Interaction_Grip_o *)0x0) goto ThrowNullReferenceException;
      leftGripBodyDominance = (leftGrip->fields).bodyDominance;
    }
  }
  rightHand = (__this->fields).rightHand;
  if (rightHand != (StressLevelZero_Interaction_Hand_o *)0x0) {
    rightAttachedInteractable =
         StressLevelZero_Interaction_Hand__get_attachedInteractable(rightHand,(MethodInfo *)0x0);
    if (((*(byte *)(UnityEngine_Object_TypeInfo + 0x127) & 2) != 0) &&
       (*(int *)(UnityEngine_Object_TypeInfo + 0xd8) == 0)) {
      FUN_1801bb8d0();
    }
    isRightHandHolding =
         UnityEngine_Object__op_Inequality
                   ((UnityEngine_Object_o *)rightAttachedInteractable,(UnityEngine_Object_o *)0x0,
                    (MethodInfo *)0x0);
    if (isRightHandHolding) {
      gripCache2 = StressLevelZero_Interaction_Grip__get_Cache((MethodInfo *)0x0);
      rightHand2 = (__this->fields).rightHand;
      if (((rightHand2 == (StressLevelZero_Interaction_Hand_o *)0x0) ||
          (rightAttachedInteractable2 =
                StressLevelZero_Interaction_Hand__get_attachedInteractable
                          (rightHand2,(MethodInfo *)0x0),
          rightAttachedInteractable2 == (StressLevelZero_Interaction_Interactable_o *)0x0)) ||
         (gameObject2 = UnityEngine_Component__get_gameObject
                                  ((UnityEngine_Component_o *)rightAttachedInteractable2,
                                   (MethodInfo *)0x0),
         gripCache2 == (Utilties_ComponentCache_Grip__o *)0x0)) goto ThrowNullReferenceException;
      hasRightGrip = Utilties_ComponentCache<object>__TryGet
                               ((Utilties_ComponentCache_object__o *)gripCache2,gameObject2,
                                (Il2CppObject **)&rightGrip,
                                Method_Utilties_ComponentCache<Grip>_TryGet__);
      if (hasRightGrip) {
        if (rightGrip == (StressLevelZero_Interaction_Grip_o *)0x0)
        goto ThrowNullReferenceException;
        rightGripBodyDominance = (rightGrip->fields).bodyDominance;
      }
    }
    leftHand3 = (__this->fields).leftHand;
    if (((leftHand3 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
        (rightHand3 = (__this->fields).rightHand,
        rightHand3 != (StressLevelZero_Interaction_Hand_o *)0x0)) &&
       (leftPhysHand = (leftHand3->fields).physHand,
       leftPhysHand != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
      refreshHandStateResult =
           StressLevelZero_VRMK_PhysHand__RefreshHandStates
                     (leftPhysHand,(leftHand3->fields).joint,(rightHand3->fields).joint,
                      (MethodInfo *)0x0);
      leftHand4 = (prevRig->fields).m_leftHand;
      if (leftHand4 != (UnityEngine_Transform_o *)0x0) {
        leftHandPos = UnityEngine_Transform__get_position
                                ((UnityEngine_Vector3_o *)&tempVecOrQuat1,leftHand4,
                                 (MethodInfo *)0x0);
        rightHand4 = (prevRig->fields).m_rightHand;
        tempVecOrQuat3.fields.x = (leftHandPos->fields).x;
        tempVecOrQuat3.fields.y = (leftHandPos->fields).y;
        leftHandX = (float)tempVecOrQuat3.fields._0_8_;
        leftHandY = SUB84(tempVecOrQuat3.fields._0_8_,4);
        leftHandZ = (leftHandPos->fields).z;
        tempVecOrQuat3.fields.z = leftHandZ;
        if (rightHand4 != (UnityEngine_Transform_o *)0x0) {
          rightHandPos = UnityEngine_Transform__get_position
                                   ((UnityEngine_Vector3_o *)&tempVecOrQuat1,rightHand4,
                                    (MethodInfo *)0x0);
          tempVecOrQuat2.fields.x = (rightHandPos->fields).x;
          tempVecOrQuat2.fields.y = (rightHandPos->fields).y;
          rightHandX = (float)tempVecOrQuat2.fields._0_8_;
          rightHandY = SUB84(tempVecOrQuat2.fields._0_8_,4);
          rightHandZ = (rightHandPos->fields).z;
          tempVecOrQuat2.fields.z = rightHandZ;
          if (refreshHandStateResult) {
            if (leftGrip == (StressLevelZero_Interaction_Grip_o *)0x0)
            goto ThrowNullReferenceException;
            leftGripHasVirtualController =
                 StressLevelZero_Interaction_Grip__get_HasVirtualController
                           (leftGrip,(MethodInfo *)0x0);
            if (!leftGripHasVirtualController) {
              StressLevelZero_Rig_PhysicsRig__StaticVirtualController
                        (__this,leftGrip,rightGrip,(UnityEngine_Vector3_o *)&tempVecOrQuat3,
                         (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
              leftHandZ = tempVecOrQuat3.fields.z;
              leftHand5 = (prevRig->fields).m_leftHand;
              if (leftHand5 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
              leftHandX = (float)tempVecOrQuat3.fields._0_8_;
              leftHandY = SUB84(tempVecOrQuat3.fields._0_8_,4);
              tempVecOrQuat1.fields.x = tempVecOrQuat3.fields.x;
              tempVecOrQuat1.fields.y = tempVecOrQuat3.fields.y;
              tempVecOrQuat1.fields.z = tempVecOrQuat3.fields.z;
              UnityEngine_Transform__set_position
                        (leftHand5,(UnityEngine_Vector3_o *)&tempVecOrQuat1,(MethodInfo *)0x0);
              rightHandZ = tempVecOrQuat2.fields.z;
              rightHand5 = (prevRig->fields).m_rightHand;
              if (rightHand5 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
              rightHandX = (float)tempVecOrQuat2.fields._0_8_;
              rightHandY = SUB84(tempVecOrQuat2.fields._0_8_,4);
              tempVecOrQuat1.fields.x = tempVecOrQuat2.fields.x;
              tempVecOrQuat1.fields.y = tempVecOrQuat2.fields.y;
              tempVecOrQuat1.fields.z = tempVecOrQuat2.fields.z;
              UnityEngine_Transform__set_position
                        (rightHand5,(UnityEngine_Vector3_o *)&tempVecOrQuat1,(MethodInfo *)0x0);
            }
          }
          rigManager = (__this->fields).field0_0x0.manager;
          if (((rigManager != (StressLevelZero_Rig_RigManager_o *)0x0) &&
              (gameWorldSkelRig = (rigManager->fields).gameWorldSkeletonRig,
              gameWorldSkelRig != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) &&
             (gameSkelBody = StressLevelZero_Rig_SkeletonRig__get_body
                                       (gameWorldSkelRig,(MethodInfo *)0x0),
             gameSkelBody != (StressLevelZero_VRMK_SLZ_Body_o *)0x0)) {
            armlength = (gameSkelBody->fields).armLength;
            rigManager = (__this->fields).field0_0x0.manager;
            if (((rigManager != (StressLevelZero_Rig_RigManager_o *)0x0) &&
                (realtimeSkelRig = (rigManager->fields).realtimeSkeletonRig,
                realtimeSkelRig != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) &&
               (realSkelBody = StressLevelZero_Rig_SkeletonRig__get_body
                                         (realtimeSkelRig,(MethodInfo *)0x0),
               realSkelBody != (StressLevelZero_VRMK_SLZ_Body_o *)0x0)) {
              realSkelBodyRefs = (realSkelBody->fields).references;
              leftHand6 = (__this->fields).leftHand;
              if (leftHand6 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                leftPhysHand2 = (leftHand6->fields).physHand;
                if (((*(byte *)(UnityEngine_Vector3_TypeInfo + 0x127) & 2) != 0) &&
                   (*(int *)(UnityEngine_Vector3_TypeInfo + 0xd8) == 0)) {
                  FUN_1801bb8d0();
                }
                tempVecOrQuat2.fields.y = leftHandY;
                tempVecOrQuat2.fields.x = leftHandX;
                tempVecOrQuat2.fields.z = leftHandZ;
                tempVecOrQuat1.fields._0_8_ = tempVec1XY;
                tempVecOrQuat1.fields.z = tempVec1Z;
                pelvisToLeftHand =
                     UnityEngine_Vector3__op_Subtraction
                               ((UnityEngine_Vector3_o *)&tempVecOrQuat3,
                                (UnityEngine_Vector3_o *)&tempVecOrQuat2,
                                (UnityEngine_Vector3_o *)&tempVecOrQuat1,(MethodInfo *)0x0);
                m_leftHand3 = (prevRig->fields).m_leftHand;
                pelvisToLeftHandXY._0_4_ = (pelvisToLeftHand->fields).x;
                pelvisToLeftHandXY._4_4_ = (pelvisToLeftHand->fields).y;
                pelvisToLeftHandZ = (pelvisToLeftHand->fields).z;
                if (m_leftHand3 != (UnityEngine_Transform_o *)0x0) {
                  leftHandRot = UnityEngine_Transform__get_rotation
                                          (&tempVecOrQuat1,m_leftHand3,(MethodInfo *)0x0);
                  leftHandRotXY._0_4_ = (leftHandRot->fields).x;
                  leftHandRotXY._4_4_ = (leftHandRot->fields).y;
                  leftHandRotZ = (leftHandRot->fields).z;
                  leftHandRotW = (leftHandRot->fields).w;
                  leftHand7 = (__this->fields).leftHand;
                  if (((leftHand7 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
                      (leftHandJoint = (leftHand7->fields).joint,
                      realSkelBodyRefs != (StressLevelZero_VRMK_SLZ_Body_References_o *)0x0)) &&
                     (rtScapula = (realSkelBodyRefs->fields).rtScapula,
                     rtScapula != (UnityEngine_Transform_o *)0x0)) {
                    rtScapulaPos = UnityEngine_Transform__get_position
                                             ((UnityEngine_Vector3_o *)&tempVecOrQuat1,rtScapula,
                                              (MethodInfo *)0x0);
                    leftHand8 = (__this->fields).leftHand;
                    rtScapulaXY._0_4_ = (rtScapulaPos->fields).x;
                    rtScapulaXY._4_4_ = (rtScapulaPos->fields).y;
                    rtScapulaZ = (rtScapulaPos->fields).z;
                    if (((leftHand8 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
                        (leftController =
                              StressLevelZero_Interaction_Hand__get_controller
                                        (leftHand8,(MethodInfo *)0x0),
                        leftController != (StressLevelZero_Rig_BaseController_o *)0x0)) &&
                       (leftGripButton_ =
                             (float)(*(leftController->klass->vtable).
                                      _19_GetSecondaryInteractionButtonAxis.methodPtr)
                                              (leftController,
                                               (leftController->klass->vtable).
                                               _19_GetSecondaryInteractionButtonAxis.method),
                       leftPhysHand2 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
                      tempVecOrQuat3.fields._0_8_ = leftHandRotXY;
                      tempVecOrQuat3.fields.z = leftHandRotZ;
                      tempVecOrQuat3.fields.w = leftHandRotW;
                      tempVecOrQuat2.fields._0_8_ = pelvisToLeftHandXY;
                      tempVecOrQuat2.fields.z = pelvisToLeftHandZ;
                      tempVecOrQuat1.fields._0_8_ = rtScapulaXY;
                      tempVecOrQuat1.fields.z = rtScapulaZ;
                      StressLevelZero_VRMK_PhysHand__UpdateHand
                                (leftPhysHand2,(UnityEngine_Vector3_o *)&tempVecOrQuat2,
                                 &tempVecOrQuat3,armlength,leftHandJoint,
                                 (UnityEngine_Vector3_o *)&tempVecOrQuat1,leftGripBodyDominance,
                                 leftGripButton_,(MethodInfo *)0x0);
                      rightHand6 = (__this->fields).rightHand;
                      if (rightHand6 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                        rightPhysHand = (rightHand6->fields).physHand;
                        tempVecOrQuat2.fields.y = rightHandY;
                        tempVecOrQuat2.fields.x = rightHandX;
                        tempVecOrQuat2.fields.z = rightHandZ;
                        tempVecOrQuat1.fields._0_8_ = tempVec1XY;
                        tempVecOrQuat1.fields.z = tempVec1Z;
                        pelvisToRightHand =
                             UnityEngine_Vector3__op_Subtraction
                                       ((UnityEngine_Vector3_o *)&tempVecOrQuat3,
                                        (UnityEngine_Vector3_o *)&tempVecOrQuat2,
                                        (UnityEngine_Vector3_o *)&tempVecOrQuat1,(MethodInfo *)0x0);
                        m_rightHand = (prevRig->fields).m_rightHand;
                        pelvisToRightHandXY._0_4_ = (pelvisToRightHand->fields).x;
                        pelvisToRightHandXY._4_4_ = (pelvisToRightHand->fields).y;
                        tempVec1Z = (pelvisToRightHand->fields).z;
                        if (m_rightHand != (UnityEngine_Transform_o *)0x0) {
                          rightHandRot = UnityEngine_Transform__get_rotation
                                                   (&tempVecOrQuat1,m_rightHand,(MethodInfo *)0x0);
                          rightHandRotXY._0_4_ = (rightHandRot->fields).x;
                          rightHandRotXY._4_4_ = (rightHandRot->fields).y;
                          rightHandRotZ = (rightHandRot->fields).z;
                          rightHandRotW = (rightHandRot->fields).w;
                          rightHand7 = (__this->fields).rightHand;
                          if (rightHand7 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                            leftShoulder = (realSkelBodyRefs->fields).leftShoulder;
                            joint = (rightHand7->fields).joint;
                            if (leftShoulder != (UnityEngine_Transform_o *)0x0) {
                              leftShoulderPos =
                                   UnityEngine_Transform__get_position
                                             ((UnityEngine_Vector3_o *)&tempVecOrQuat1,leftShoulder,
                                              (MethodInfo *)0x0);
                              rightHand8 = (__this->fields).rightHand;
                              leftShoulderXY._0_4_ = (leftShoulderPos->fields).x;
                              leftShoulderXY._4_4_ = (leftShoulderPos->fields).y;
                              leftShoulderZ = (leftShoulderPos->fields).z;
                              if (((rightHand8 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
                                  (rightController =
                                        StressLevelZero_Interaction_Hand__get_controller
                                                  (rightHand8,(MethodInfo *)0x0),
                                  rightController != (StressLevelZero_Rig_BaseController_o *)0x0))
                                 && (gripInput = (float)(*(rightController->klass->vtable).
                                                          _19_GetSecondaryInteractionButtonAxis.
                                                          methodPtr)(rightController,
                                                                     (rightController->klass->vtable
                                                                     ).
                                                  _19_GetSecondaryInteractionButtonAxis.method),
                                    rightPhysHand != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
                                tempVecOrQuat3.fields._0_8_ = rightHandRotXY;
                                tempVecOrQuat3.fields.z = rightHandRotZ;
                                tempVecOrQuat3.fields.w = rightHandRotW;
                                tempVecOrQuat2.fields._0_8_ = pelvisToRightHandXY;
                                tempVecOrQuat2.fields.z = tempVec1Z;
                                tempVecOrQuat1.fields._0_8_ = leftShoulderXY;
                                tempVecOrQuat1.fields.z = leftShoulderZ;
                                StressLevelZero_VRMK_PhysHand__UpdateHand
                                          (rightPhysHand,(UnityEngine_Vector3_o *)&tempVecOrQuat2,
                                           &tempVecOrQuat3,armlength,joint,
                                           (UnityEngine_Vector3_o *)&tempVecOrQuat1,
                                           rightGripBodyDominance,gripInput,(MethodInfo *)0x0);
                                leftHand9 = (__this->fields).leftHand;
                                if (leftHand9 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                                  StressLevelZero_Interaction_Hand__OrderedFixedUpdate
                                            (leftHand9,(MethodInfo *)0x0);
                                  rightHand9 = (__this->fields).rightHand;
                                  if (rightHand9 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                                    StressLevelZero_Interaction_Hand__OrderedFixedUpdate
                                              (rightHand9,(MethodInfo *)0x0);
                                    physBody3 = (__this->fields).physBody;
                                    if ((physBody3 != (StressLevelZero_VRMK_PhysBody_o *)0x0) &&
                                       (rbPelvis = StressLevelZero_VRMK_PhysBody__get_rbPelvis
                                                             (physBody3,(MethodInfo *)0x0),
                                       rbPelvis != (UnityEngine_Rigidbody_o *)0x0)) {
                                      pelvisTransform =
                                           UnityEngine_Component__get_transform
                                                     ((UnityEngine_Component_o *)rbPelvis,
                                                      (MethodInfo *)0x0);
                                      if (((*(byte *)(UnityEngine_Quaternion_TypeInfo + 0x127) & 2)
                                           != 0) &&
                                         (*(int *)(UnityEngine_Quaternion_TypeInfo + 0xd8) == 0)) {
                                        FUN_1801bb8d0();
                                      }
                                      quaternionIdentity =
                                           UnityEngine_Quaternion__get_identity
                                                     (&tempVecOrQuat1,(MethodInfo *)0x0);
                                      if (pelvisTransform != (UnityEngine_Transform_o *)0x0) {
                                        tempVecOrQuat1.fields.x = (quaternionIdentity->fields).x;
                                        tempVecOrQuat1.fields.y = (quaternionIdentity->fields).y;
                                        tempVecOrQuat1.fields.z = (quaternionIdentity->fields).z;
                                        tempVecOrQuat1.fields.w = (quaternionIdentity->fields).w;
                                        UnityEngine_Transform__set_localRotation
                                                  (pelvisTransform,&tempVecOrQuat1,(MethodInfo *)0x0
                                                  );
                                        physBody4 = (__this->fields).physBody;
                                        if ((physBody4 != (StressLevelZero_VRMK_PhysBody_o *)0x0) &&
                                           (rbKnee = StressLevelZero_VRMK_PhysBody__get_rbKnee
                                                               (physBody4,(MethodInfo *)0x0),
                                           rbKnee != (UnityEngine_Rigidbody_o *)0x0)) {
                                          kneeTransform =
                                               UnityEngine_Component__get_transform
                                                         ((UnityEngine_Component_o *)rbKnee,
                                                          (MethodInfo *)0x0);
                                          quaternionIdentity2 =
                                               UnityEngine_Quaternion__get_identity
                                                         (&tempVecOrQuat1,(MethodInfo *)0x0);
                                          if (kneeTransform != (UnityEngine_Transform_o *)0x0) {
                                            tempVecOrQuat1.fields.x =
                                                 (quaternionIdentity2->fields).x;
                                            tempVecOrQuat1.fields.y =
                                                 (quaternionIdentity2->fields).y;
                                            tempVecOrQuat1.fields.z =
                                                 (quaternionIdentity2->fields).z;
                                            tempVecOrQuat1.fields.w =
                                                 (quaternionIdentity2->fields).w;
                                            UnityEngine_Transform__set_localRotation
                                                      (kneeTransform,&tempVecOrQuat1,
                                                       (MethodInfo *)0x0);
                                            if ((__this->fields)._ballLocoEnabled == false) {
                                              return;
                                            }
                                            physBody5 = (__this->fields).physBody;
                                            if (physBody5 != (StressLevelZero_VRMK_PhysBody_o *)0x0)
                                            {
                                              StressLevelZero_VRMK_PhysBody__SetBodyMassDistribution
                                                        (physBody5,(MethodInfo *)0x0);
                                              m_pelvis4 = (prevRig->fields).m_pelvis;
                                              physBody6 = (__this->fields).physBody;
                                              if (m_pelvis4 != (UnityEngine_Transform_o *)0x0) {
                                                pelvisLocalPos2 =
                                                     UnityEngine_Transform__get_localPosition
                                                               ((UnityEngine_Vector3_o *)
                                                                &tempVecOrQuat2,m_pelvis4,
                                                                (MethodInfo *)0x0);
                                                tempVecOrQuat1.fields.x =
                                                     (pelvisLocalPos2->fields).x;
                                                tempVecOrQuat1.fields.y =
                                                     (pelvisLocalPos2->fields).y;
                                                tempVecOrQuat1.fields.z =
                                                     (pelvisLocalPos2->fields).z;
                                                if (physBody6 !=
                                                    (StressLevelZero_VRMK_PhysBody_o *)0x0) {
                                                  StressLevelZero_VRMK_PhysBody__UpdateKnee
                                                            (physBody6,tempVecOrQuat1.fields.y,
                                                             (MethodInfo *)0x0);
                                                  m_head4 = (prevRig->fields).m_head;
                                                  physBody7 = (__this->fields).physBody;
                                                  if (m_head4 != (UnityEngine_Transform_o *)0x0) {
                                                    headPos3 = UnityEngine_Transform__get_position
                                                                         ((UnityEngine_Vector3_o *)
                                                                          &tempVecOrQuat1,m_head4,
                                                                          (MethodInfo *)0x0);
                                                    headXY._0_4_ = (headPos3->fields).x;
                                                    headXY._4_4_ = (headPos3->fields).y;
                                                    tempVec1Z = (headPos3->fields).z;
                                                    if (((*(byte *)(UnityEngine_Vector3_TypeInfo +
                                                                   0x127) & 2) != 0) &&
                                                       (*(int *)(UnityEngine_Vector3_TypeInfo + 0xd8
                                                                ) == 0)) {
                                                      FUN_1801bb8d0();
                                                    }
                                                    tempVecOrQuat2.fields._0_8_ = headXY;
                                                    tempVecOrQuat2.fields.z = tempVec1Z;
                                                    tempVecOrQuat1.fields._0_8_ = tempVec22XY;
                                                    tempVecOrQuat1.fields.z = tempVec2Z;
                                                    neckBaseToHead =
                                                         UnityEngine_Vector3__op_Subtraction
                                                                   ((UnityEngine_Vector3_o *)
                                                                    &tempVecOrQuat3,
                                                                    (UnityEngine_Vector3_o *)
                                                                    &tempVecOrQuat2,
                                                                    (UnityEngine_Vector3_o *)
                                                                    &tempVecOrQuat1,
                                                                    (MethodInfo *)0x0);
                                                    neckBaseToHeadXY._0_4_ =
                                                         (neckBaseToHead->fields).x;
                                                    neckBaseToHeadXY._4_4_ =
                                                         (neckBaseToHead->fields).y;
                                                    tempVec1Z = (neckBaseToHead->fields).z;
                                                    fixedDeltaTime =
                                                         UnityEngine_Time__get_fixedDeltaTime
                                                                   ((MethodInfo *)0x0);
                                                    tempVecOrQuat1.fields._0_8_ = neckBaseToHeadXY;
                                                    tempVecOrQuat1.fields.z = tempVec1Z;
                                                    targetHeadPos =
                                                         UnityEngine_Vector3__op_Division
                                                                   ((UnityEngine_Vector3_o *)
                                                                    &tempVecOrQuat2,
                                                                    (UnityEngine_Vector3_o *)
                                                                    &tempVecOrQuat1,fixedDeltaTime,
                                                                    (MethodInfo *)0x0);
                                                    if (physBody7 !=
                                                        (StressLevelZero_VRMK_PhysBody_o *)0x0) {
                                                      tempVecOrQuat1.fields.x =
                                                           (targetHeadPos->fields).x;
                                                      tempVecOrQuat1.fields.y =
                                                           (targetHeadPos->fields).y;
                                                      tempVecOrQuat1.fields.z =
                                                           (targetHeadPos->fields).z;
                                                      StressLevelZero_VRMK_PhysBody__ApplyForce
                                                                (physBody7,
                                                                 (UnityEngine_Vector3_o *)
                                                                 &tempVecOrQuat1,(MethodInfo *)0x0);
                                                      return;
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
ThrowNullReferenceException:
                    /* WARNING: Subroutine does not return */
  ThrowNullReferenceException();
}

