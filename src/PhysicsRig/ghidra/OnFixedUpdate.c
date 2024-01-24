
/* WARNING: Unable to use type for symbol tempVec1XY */

void StressLevelZero.Rig.PhysicsRig$$OnFixedUpdate
               (StressLevelZero_Rig_PhysicsRig_o *__this,MethodInfo *method)

{
  float armlength;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  float fVar7;
  StressLevelZero_VRMK_PhysBody_o *pSVar8;
  UnityEngine_ConfigurableJoint_o *pUVar9;
  StressLevelZero_Interaction_Hand_o *pSVar10;
  StressLevelZero_Interaction_Hand_o *pSVar11;
  StressLevelZero_VRMK_PhysHand_o *pSVar12;
  StressLevelZero_Rig_SkeletonRig_o *pSVar13;
  StressLevelZero_VRMK_SLZ_Body_References_o *pSVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  bool bVar18;
  uint prevRigIdx;
  UnityEngine_Vector3_o *headPos;
  UnityEngine_Transform_o *prevRigTransform;
  UnityEngine_Vector3_o *pelvisLocalPos;
  UnityEngine_Vector3_o *nearPelvisWorldPos?;
  UnityEngine_Vector3_o *pelvisPos;
  UnityEngine_Vector3_o *headPos2;
  UnityEngine_Vector3_o *pelvisToHead;
  UnityEngine_Vector3_o *pelvisAtHeadHeight;
  UnityEngine_Vector3_o *pelvisAtHeadHeightLocalPos;
  UnityEngine_Quaternion_o *pUVar19;
  StressLevelZero_Interaction_Interactable_o *pSVar20;
  Utilties_ComponentCache_Grip__o *pUVar21;
  UnityEngine_GameObject_o *pUVar22;
  UnityEngine_Vector3_o *pUVar23;
  StressLevelZero_VRMK_SLZ_Body_o *pSVar24;
  StressLevelZero_Rig_BaseController_o *pSVar25;
  UnityEngine_Rigidbody_o *pUVar26;
  UnityEngine_Transform_o *pUVar27;
  longlong ex;
  float fVar28;
  float fVar29;
  float gripInput;
  float fVar30;
  float fixedDeltaTime;
  float fVar31;
  float fVar32;
  float fVar33;
  float bodyDominance;
  float fVar34;
  StressLevelZero_Interaction_Grip_o *local_118;
  StressLevelZero_Interaction_Grip_o *local_110;
  UnityEngine_Vector3_o nearPelvisLocalPos?;
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
  UnityEngine_Transform_o *m_head2;
  UnityEngine_Joint_o *headJoint;
  StressLevelZero_Rig_Rig_o *prevRig;
  StressLevelZero_Rig_RigManager_o *rigManager;
  StressLevelZero_Rig_Rig_array *rigs;
  float tempVec1Z;
  undefined8 tempVec22XY;
  undefined8 tempVec2XY;
  float tempVec2Z;
  
  if (DAT_181ebb17a == '\0') {
    FUN_1801ad630(0x6024);
    DAT_181ebb17a = '\x01';
  }
  rigManager = (__this->fields).field0_0x0.manager;
  local_118 = (StressLevelZero_Interaction_Grip_o *)0x0;
  local_110 = (StressLevelZero_Interaction_Grip_o *)0x0;
  if ((rigManager == (StressLevelZero_Rig_RigManager_o *)0x0) ||
     (rigs = (rigManager->fields).rigs, rigs == (StressLevelZero_Rig_Rig_array *)0x0)) {
ThrowNullReferenceException:
                    /* WARNING: Subroutine does not return */
    ThrowNullReferenceException();
  }
  prevRigIdx = StressLevelZero.Utils$$Mod
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
  headPos = UnityEngine.Transform$$get_position
                      ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_head,(MethodInfo *)0x0);
  headY = (headPos->fields).y;
  (__this->fields)._lastHeadPos.fields.x = (headPos->fields).x;
  (__this->fields)._lastHeadPos.fields.y = headY;
  (__this->fields)._lastHeadPos.fields.z = (headPos->fields).z;
  if (prevRig == (StressLevelZero_Rig_Rig_o *)0x0) goto ThrowNullReferenceException;
  prevRigTransform =
       UnityEngine.Component$$get_transform((UnityEngine_Component_o *)prevRig,(MethodInfo *)0x0);
  m_pelvis = (prevRig->fields).m_pelvis;
  if (m_pelvis == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  pelvisLocalPos =
       UnityEngine.Transform$$get_localPosition
                 ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_pelvis,(MethodInfo *)0x0);
  tempVecOrQuat1.fields.x = (pelvisLocalPos->fields).x;
  tempVecOrQuat1.fields.y = (pelvisLocalPos->fields).y;
  tempVecOrQuat1.fields.z = (pelvisLocalPos->fields).z;
  nearPelvisLocalPos?.fields.x = 0.0;
  nearPelvisLocalPos?.fields.y = 0.0;
  nearPelvisLocalPos?.fields.z = 0.0;
  UnityEngine.Vector3$$Set(&nearPelvisLocalPos?,0.0,SUB84(tempVecOrQuat1.fields._0_8_,4),-0.04);
  if (prevRigTransform == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  tempVecOrQuat2.fields.x = nearPelvisLocalPos?.fields.x;
  tempVecOrQuat2.fields.y = nearPelvisLocalPos?.fields.y;
  tempVecOrQuat2.fields.z = nearPelvisLocalPos?.fields.z;
  nearPelvisWorldPos? =
       UnityEngine.Transform$$TransformPoint
                 ((UnityEngine_Vector3_o *)&tempVecOrQuat1,prevRigTransform,
                  (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
  m_pelvis2 = (__this->fields).field0_0x0.m_pelvis;
  tempVec1Z = (nearPelvisWorldPos?->fields).z;
  tempVec1XY._0_4_ = (nearPelvisWorldPos?->fields).x;
  tempVec1XY._4_4_ = (nearPelvisWorldPos?->fields).y;
  if (m_pelvis2 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  pelvisPos = UnityEngine.Transform$$get_position
                        ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_pelvis2,(MethodInfo *)0x0);
  m_head2 = (prevRig->fields).m_head;
  tempVec2XY._0_4_ = (pelvisPos->fields).x;
  tempVec2XY._4_4_ = (pelvisPos->fields).y;
  tempVec2Z = (pelvisPos->fields).z;
  if (m_head2 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  headPos2 = UnityEngine.Transform$$get_position
                       ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_head2,(MethodInfo *)0x0);
  tempVecOrQuat3.fields.x = (headPos2->fields).x;
  tempVecOrQuat3.fields.y = (headPos2->fields).y;
  tempVecOrQuat3.fields.z = (headPos2->fields).z;
  if (((*(byte *)(UnityEngine.Vector3_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine.Vector3_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  tempVecOrQuat2.fields._0_8_ = tempVec1XY;
  tempVecOrQuat2.fields.z = tempVec1Z;
  pelvisToHead = UnityEngine.Vector3$$op_Subtraction
                           ((UnityEngine_Vector3_o *)&tempVecOrQuat1,
                            (UnityEngine_Vector3_o *)&tempVecOrQuat3,
                            (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
  tempVecOrQuat2.fields.x = (pelvisToHead->fields).x;
  tempVecOrQuat2.fields.y = (pelvisToHead->fields).y;
  tempVecOrQuat2.fields.z = (pelvisToHead->fields).z;
  tempVecOrQuat3.fields._0_8_ = tempVec2XY;
  tempVecOrQuat3.fields.z = tempVec2Z;
  pelvisAtHeadHeight =
       UnityEngine.Vector3$$op_Addition
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
          UnityEngine.Transform$$InverseTransformPoint
                    ((UnityEngine_Vector3_o *)&tempVecOrQuat1,m_pelvis3,
                     (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0),
     headJoint == (UnityEngine_Joint_o *)0x0)) goto ThrowNullReferenceException;
  tempVecOrQuat2.fields.x = (pelvisAtHeadHeightLocalPos->fields).x;
  tempVecOrQuat2.fields.y = (pelvisAtHeadHeightLocalPos->fields).y;
  tempVecOrQuat2.fields.z = (pelvisAtHeadHeightLocalPos->fields).z;
  UnityEngine.Joint$$set_connectedAnchor
            (headJoint,(UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
  pSVar8 = (__this->fields).physBody;
  if (pSVar8 == (StressLevelZero_VRMK_PhysBody_o *)0x0) goto ThrowNullReferenceException;
  pUVar27 = (prevRig->fields).m_head;
  pUVar9 = (pSVar8->fields).headJoint;
  if (pUVar27 == (UnityEngine_Transform_o *)0x0) goto ThrowNullReferenceException;
  pUVar19 = UnityEngine.Transform$$get_rotation(&tempVecOrQuat1,pUVar27,(MethodInfo *)0x0);
  uVar15._0_4_ = (pUVar19->fields).x;
  uVar15._4_4_ = (pUVar19->fields).y;
  fVar34 = (pUVar19->fields).z;
  tempVecOrQuat1.fields.w = (pUVar19->fields).w;
  if (((*(byte *)(UnityEngine.Quaternion_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine.Quaternion_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  tempVecOrQuat1.fields._0_8_ = uVar15;
  tempVecOrQuat1.fields.z = fVar34;
  pUVar19 = UnityEngine.Quaternion$$Inverse(&tempVecOrQuat2,&tempVecOrQuat1,(MethodInfo *)0x0);
  tempVecOrQuat1.fields.x = (__this->fields)._initialPelvisRotation.fields.x;
  tempVecOrQuat1.fields.y = (__this->fields)._initialPelvisRotation.fields.y;
  tempVecOrQuat1.fields.z = (__this->fields)._initialPelvisRotation.fields.z;
  tempVecOrQuat1.fields.w = (__this->fields)._initialPelvisRotation.fields.w;
  tempVecOrQuat2.fields.x = (pUVar19->fields).x;
  tempVecOrQuat2.fields.y = (pUVar19->fields).y;
  tempVecOrQuat2.fields.z = (pUVar19->fields).z;
  tempVecOrQuat2.fields.w = (pUVar19->fields).w;
  pUVar19 = UnityEngine.Quaternion$$op_Multiply
                      (&tempVecOrQuat3,&tempVecOrQuat2,&tempVecOrQuat1,(MethodInfo *)0x0);
  if (pUVar9 == (UnityEngine_ConfigurableJoint_o *)0x0) goto ThrowNullReferenceException;
  tempVecOrQuat1.fields.x = (pUVar19->fields).x;
  tempVecOrQuat1.fields.y = (pUVar19->fields).y;
  tempVecOrQuat1.fields.z = (pUVar19->fields).z;
  tempVecOrQuat1.fields.w = (pUVar19->fields).w;
  UnityEngine.ConfigurableJoint$$set_targetRotation(pUVar9,&tempVecOrQuat1,(MethodInfo *)0x0);
  pSVar10 = (__this->fields).leftHand;
  bodyDominance = 1.0;
  fVar34 = 1.0;
  if (pSVar10 == (StressLevelZero_Interaction_Hand_o *)0x0) goto ThrowNullReferenceException;
  pSVar20 = StressLevelZero.Interaction.Hand$$get_attachedInteractable(pSVar10,(MethodInfo *)0x0);
  if (((*(byte *)(UnityEngine.Object_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine.Object_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  bVar18 = UnityEngine.Object$$op_Inequality
                     ((UnityEngine_Object_o *)pSVar20,(UnityEngine_Object_o *)0x0,(MethodInfo *)0x0)
  ;
  if (bVar18) {
    pUVar21 = StressLevelZero.Interaction.Grip$$get_Cache((MethodInfo *)0x0);
    pSVar10 = (__this->fields).leftHand;
    if (((pSVar10 == (StressLevelZero_Interaction_Hand_o *)0x0) ||
        (pSVar20 = StressLevelZero.Interaction.Hand$$get_attachedInteractable
                             (pSVar10,(MethodInfo *)0x0),
        pSVar20 == (StressLevelZero_Interaction_Interactable_o *)0x0)) ||
       (pUVar22 = UnityEngine.Component$$get_gameObject
                            ((UnityEngine_Component_o *)pSVar20,(MethodInfo *)0x0),
       pUVar21 == (Utilties_ComponentCache_Grip__o *)0x0)) goto LAB_1804309fe;
    bVar18 = Utilties.ComponentCache<object>$$TryGet
                       ((Utilties_ComponentCache_object__o *)pUVar21,pUVar22,
                        (Il2CppObject **)&local_118,Method$Utilties.ComponentCache<Grip>.TryGet());
    if (bVar18) {
      if (local_118 == (StressLevelZero_Interaction_Grip_o *)0x0) goto LAB_1804309fe;
      fVar34 = (local_118->fields).bodyDominance;
    }
  }
  pSVar10 = (__this->fields).rightHand;
  if (pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) {
    pSVar20 = StressLevelZero.Interaction.Hand$$get_attachedInteractable(pSVar10,(MethodInfo *)0x0);
    if (((*(byte *)(UnityEngine.Object_TypeInfo + 0x127) & 2) != 0) &&
       (*(int *)(UnityEngine.Object_TypeInfo + 0xd8) == 0)) {
      FUN_1801bb8d0();
    }
    bVar18 = UnityEngine.Object$$op_Inequality
                       ((UnityEngine_Object_o *)pSVar20,(UnityEngine_Object_o *)0x0,
                        (MethodInfo *)0x0);
    if (bVar18) {
      pUVar21 = StressLevelZero.Interaction.Grip$$get_Cache((MethodInfo *)0x0);
      pSVar10 = (__this->fields).rightHand;
      if (((pSVar10 == (StressLevelZero_Interaction_Hand_o *)0x0) ||
          (pSVar20 = StressLevelZero.Interaction.Hand$$get_attachedInteractable
                               (pSVar10,(MethodInfo *)0x0),
          pSVar20 == (StressLevelZero_Interaction_Interactable_o *)0x0)) ||
         (pUVar22 = UnityEngine.Component$$get_gameObject
                              ((UnityEngine_Component_o *)pSVar20,(MethodInfo *)0x0),
         pUVar21 == (Utilties_ComponentCache_Grip__o *)0x0)) goto LAB_1804309fe;
      bVar18 = Utilties.ComponentCache<object>$$TryGet
                         ((Utilties_ComponentCache_object__o *)pUVar21,pUVar22,
                          (Il2CppObject **)&local_110,Method$Utilties.ComponentCache<Grip>.TryGet())
      ;
      if (bVar18) {
        if (local_110 == (StressLevelZero_Interaction_Grip_o *)0x0) goto LAB_1804309fe;
        bodyDominance = (local_110->fields).bodyDominance;
      }
    }
    pSVar10 = (__this->fields).leftHand;
    if (((pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
        (pSVar11 = (__this->fields).rightHand, pSVar11 != (StressLevelZero_Interaction_Hand_o *)0x0)
        ) && (pSVar12 = (pSVar10->fields).physHand,
             pSVar12 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
      bVar18 = StressLevelZero.VRMK.PhysHand$$RefreshHandStates
                         (pSVar12,(pSVar10->fields).joint,(pSVar11->fields).joint,(MethodInfo *)0x0)
      ;
      pUVar27 = (prevRig->fields).m_leftHand;
      if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
        pUVar23 = UnityEngine.Transform$$get_position
                            ((UnityEngine_Vector3_o *)&tempVecOrQuat1,pUVar27,(MethodInfo *)0x0);
        pUVar27 = (prevRig->fields).m_rightHand;
        tempVecOrQuat3.fields.x = (pUVar23->fields).x;
        tempVecOrQuat3.fields.y = (pUVar23->fields).y;
        fVar31 = (float)tempVecOrQuat3.fields._0_8_;
        fVar30 = SUB84(tempVecOrQuat3.fields._0_8_,4);
        fVar29 = (pUVar23->fields).z;
        tempVecOrQuat3.fields.z = fVar29;
        if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
          pUVar23 = UnityEngine.Transform$$get_position
                              ((UnityEngine_Vector3_o *)&tempVecOrQuat1,pUVar27,(MethodInfo *)0x0);
          tempVecOrQuat2.fields.x = (pUVar23->fields).x;
          tempVecOrQuat2.fields.y = (pUVar23->fields).y;
          fVar32 = (float)tempVecOrQuat2.fields._0_8_;
          fVar33 = SUB84(tempVecOrQuat2.fields._0_8_,4);
          fVar28 = (pUVar23->fields).z;
          tempVecOrQuat2.fields.z = fVar28;
          if (bVar18) {
            if (local_118 == (StressLevelZero_Interaction_Grip_o *)0x0) goto LAB_1804309fe;
            bVar18 = StressLevelZero.Interaction.Grip$$get_HasVirtualController
                               (local_118,(MethodInfo *)0x0);
            if (!bVar18) {
              StressLevelZero.Rig.PhysicsRig$$StaticVirtualController
                        (__this,local_118,local_110,(UnityEngine_Vector3_o *)&tempVecOrQuat3,
                         (UnityEngine_Vector3_o *)&tempVecOrQuat2,(MethodInfo *)0x0);
              fVar29 = tempVecOrQuat3.fields.z;
              pUVar27 = (prevRig->fields).m_leftHand;
              if (pUVar27 == (UnityEngine_Transform_o *)0x0) goto LAB_1804309fe;
              fVar31 = (float)tempVecOrQuat3.fields._0_8_;
              fVar30 = SUB84(tempVecOrQuat3.fields._0_8_,4);
              tempVecOrQuat1.fields.x = tempVecOrQuat3.fields.x;
              tempVecOrQuat1.fields.y = tempVecOrQuat3.fields.y;
              tempVecOrQuat1.fields.z = tempVecOrQuat3.fields.z;
              UnityEngine.Transform$$set_position
                        (pUVar27,(UnityEngine_Vector3_o *)&tempVecOrQuat1,(MethodInfo *)0x0);
              fVar28 = tempVecOrQuat2.fields.z;
              pUVar27 = (prevRig->fields).m_rightHand;
              if (pUVar27 == (UnityEngine_Transform_o *)0x0) goto LAB_1804309fe;
              fVar32 = (float)tempVecOrQuat2.fields._0_8_;
              fVar33 = SUB84(tempVecOrQuat2.fields._0_8_,4);
              tempVecOrQuat1.fields.x = tempVecOrQuat2.fields.x;
              tempVecOrQuat1.fields.y = tempVecOrQuat2.fields.y;
              tempVecOrQuat1.fields.z = tempVecOrQuat2.fields.z;
              UnityEngine.Transform$$set_position
                        (pUVar27,(UnityEngine_Vector3_o *)&tempVecOrQuat1,(MethodInfo *)0x0);
            }
          }
          rigManager = (__this->fields).field0_0x0.manager;
          if (((rigManager != (StressLevelZero_Rig_RigManager_o *)0x0) &&
              (pSVar13 = (rigManager->fields).gameWorldSkeletonRig,
              pSVar13 != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) &&
             (pSVar24 = StressLevelZero.Rig.SkeletonRig$$get_body(pSVar13,(MethodInfo *)0x0),
             pSVar24 != (StressLevelZero_VRMK_SLZ_Body_o *)0x0)) {
            armlength = (pSVar24->fields).armLength;
            rigManager = (__this->fields).field0_0x0.manager;
            if (((rigManager != (StressLevelZero_Rig_RigManager_o *)0x0) &&
                (pSVar13 = (rigManager->fields).realtimeSkeletonRig,
                pSVar13 != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) &&
               (pSVar24 = StressLevelZero.Rig.SkeletonRig$$get_body(pSVar13,(MethodInfo *)0x0),
               pSVar24 != (StressLevelZero_VRMK_SLZ_Body_o *)0x0)) {
              pSVar14 = (pSVar24->fields).references;
              pSVar10 = (__this->fields).leftHand;
              if (pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                pSVar12 = (pSVar10->fields).physHand;
                if (((*(byte *)(UnityEngine.Vector3_TypeInfo + 0x127) & 2) != 0) &&
                   (*(int *)(UnityEngine.Vector3_TypeInfo + 0xd8) == 0)) {
                  FUN_1801bb8d0();
                }
                tempVecOrQuat2.fields.y = fVar30;
                tempVecOrQuat2.fields.x = fVar31;
                tempVecOrQuat2.fields.z = fVar29;
                tempVecOrQuat1.fields._0_8_ = tempVec1XY;
                tempVecOrQuat1.fields.z = tempVec1Z;
                pUVar23 = UnityEngine.Vector3$$op_Subtraction
                                    ((UnityEngine_Vector3_o *)&tempVecOrQuat3,
                                     (UnityEngine_Vector3_o *)&tempVecOrQuat2,
                                     (UnityEngine_Vector3_o *)&tempVecOrQuat1,(MethodInfo *)0x0);
                pUVar27 = (prevRig->fields).m_leftHand;
                uVar1._0_4_ = (pUVar23->fields).x;
                uVar1._4_4_ = (pUVar23->fields).y;
                fVar29 = (pUVar23->fields).z;
                if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
                  pUVar19 = UnityEngine.Transform$$get_rotation
                                      (&tempVecOrQuat1,pUVar27,(MethodInfo *)0x0);
                  uVar16._0_4_ = (pUVar19->fields).x;
                  uVar16._4_4_ = (pUVar19->fields).y;
                  fVar31 = (pUVar19->fields).z;
                  fVar30 = (pUVar19->fields).w;
                  pSVar10 = (__this->fields).leftHand;
                  if (((pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
                      (pUVar9 = (pSVar10->fields).joint,
                      pSVar14 != (StressLevelZero_VRMK_SLZ_Body_References_o *)0x0)) &&
                     (pUVar27 = (pSVar14->fields).rtScapula,
                     pUVar27 != (UnityEngine_Transform_o *)0x0)) {
                    pUVar23 = UnityEngine.Transform$$get_position
                                        ((UnityEngine_Vector3_o *)&tempVecOrQuat1,pUVar27,
                                         (MethodInfo *)0x0);
                    pSVar10 = (__this->fields).leftHand;
                    uVar2._0_4_ = (pUVar23->fields).x;
                    uVar2._4_4_ = (pUVar23->fields).y;
                    fVar7 = (pUVar23->fields).z;
                    if (((pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
                        (pSVar25 = StressLevelZero.Interaction.Hand$$get_controller
                                             (pSVar10,(MethodInfo *)0x0),
                        pSVar25 != (StressLevelZero_Rig_BaseController_o *)0x0)) &&
                       (gripInput = (float)(*(pSVar25->klass->vtable).
                                             _19_GetSecondaryInteractionButtonAxis.methodPtr)
                                                     (pSVar25,(pSVar25->klass->vtable).
                                                              _19_GetSecondaryInteractionButtonAxis.
                                                              method),
                       pSVar12 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
                      tempVecOrQuat3.fields._0_8_ = uVar16;
                      tempVecOrQuat3.fields.z = fVar31;
                      tempVecOrQuat3.fields.w = fVar30;
                      tempVecOrQuat2.fields._0_8_ = uVar1;
                      tempVecOrQuat2.fields.z = fVar29;
                      tempVecOrQuat1.fields._0_8_ = uVar2;
                      tempVecOrQuat1.fields.z = fVar7;
                      StressLevelZero.VRMK.PhysHand$$UpdateHand
                                (pSVar12,(UnityEngine_Vector3_o *)&tempVecOrQuat2,&tempVecOrQuat3,
                                 armlength,pUVar9,(UnityEngine_Vector3_o *)&tempVecOrQuat1,fVar34,
                                 gripInput,(MethodInfo *)0x0);
                      pSVar10 = (__this->fields).rightHand;
                      if (pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                        pSVar12 = (pSVar10->fields).physHand;
                        tempVecOrQuat2.fields.y = fVar33;
                        tempVecOrQuat2.fields.x = fVar32;
                        tempVecOrQuat2.fields.z = fVar28;
                        tempVecOrQuat1.fields._0_8_ = tempVec1XY;
                        tempVecOrQuat1.fields.z = tempVec1Z;
                        pUVar23 = UnityEngine.Vector3$$op_Subtraction
                                            ((UnityEngine_Vector3_o *)&tempVecOrQuat3,
                                             (UnityEngine_Vector3_o *)&tempVecOrQuat2,
                                             (UnityEngine_Vector3_o *)&tempVecOrQuat1,
                                             (MethodInfo *)0x0);
                        pUVar27 = (prevRig->fields).m_rightHand;
                        uVar3._0_4_ = (pUVar23->fields).x;
                        uVar3._4_4_ = (pUVar23->fields).y;
                        tempVec1Z = (pUVar23->fields).z;
                        if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
                          pUVar19 = UnityEngine.Transform$$get_rotation
                                              (&tempVecOrQuat1,pUVar27,(MethodInfo *)0x0);
                          uVar17._0_4_ = (pUVar19->fields).x;
                          uVar17._4_4_ = (pUVar19->fields).y;
                          fVar34 = (pUVar19->fields).z;
                          fVar29 = (pUVar19->fields).w;
                          pSVar10 = (__this->fields).rightHand;
                          if (pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                            pUVar27 = (pSVar14->fields).leftShoulder;
                            pUVar9 = (pSVar10->fields).joint;
                            if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
                              pUVar23 = UnityEngine.Transform$$get_position
                                                  ((UnityEngine_Vector3_o *)&tempVecOrQuat1,pUVar27,
                                                   (MethodInfo *)0x0);
                              pSVar10 = (__this->fields).rightHand;
                              uVar4._0_4_ = (pUVar23->fields).x;
                              uVar4._4_4_ = (pUVar23->fields).y;
                              fVar31 = (pUVar23->fields).z;
                              if (((pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
                                  (pSVar25 = StressLevelZero.Interaction.Hand$$get_controller
                                                       (pSVar10,(MethodInfo *)0x0),
                                  pSVar25 != (StressLevelZero_Rig_BaseController_o *)0x0)) &&
                                 (fVar30 = (float)(*(pSVar25->klass->vtable).
                                                    _19_GetSecondaryInteractionButtonAxis.methodPtr)
                                                            (pSVar25,(pSVar25->klass->vtable).
                                                                                                                                          
                                                  _19_GetSecondaryInteractionButtonAxis.method),
                                 pSVar12 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
                                tempVecOrQuat3.fields._0_8_ = uVar17;
                                tempVecOrQuat3.fields.z = fVar34;
                                tempVecOrQuat3.fields.w = fVar29;
                                tempVecOrQuat2.fields._0_8_ = uVar3;
                                tempVecOrQuat2.fields.z = tempVec1Z;
                                tempVecOrQuat1.fields._0_8_ = uVar4;
                                tempVecOrQuat1.fields.z = fVar31;
                                StressLevelZero.VRMK.PhysHand$$UpdateHand
                                          (pSVar12,(UnityEngine_Vector3_o *)&tempVecOrQuat2,
                                           &tempVecOrQuat3,armlength,pUVar9,
                                           (UnityEngine_Vector3_o *)&tempVecOrQuat1,bodyDominance,
                                           fVar30,(MethodInfo *)0x0);
                                pSVar10 = (__this->fields).leftHand;
                                if (pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                                  StressLevelZero.Interaction.Hand$$OrderedFixedUpdate
                                            (pSVar10,(MethodInfo *)0x0);
                                  pSVar10 = (__this->fields).rightHand;
                                  if (pSVar10 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                                    StressLevelZero.Interaction.Hand$$OrderedFixedUpdate
                                              (pSVar10,(MethodInfo *)0x0);
                                    pSVar8 = (__this->fields).physBody;
                                    if ((pSVar8 != (StressLevelZero_VRMK_PhysBody_o *)0x0) &&
                                       (pUVar26 = StressLevelZero.VRMK.PhysBody$$get_rbPelvis
                                                            (pSVar8,(MethodInfo *)0x0),
                                       pUVar26 != (UnityEngine_Rigidbody_o *)0x0)) {
                                      pUVar27 = UnityEngine.Component$$get_transform
                                                          ((UnityEngine_Component_o *)pUVar26,
                                                           (MethodInfo *)0x0);
                                      if (((*(byte *)(UnityEngine.Quaternion_TypeInfo + 0x127) & 2)
                                           != 0) &&
                                         (*(int *)(UnityEngine.Quaternion_TypeInfo + 0xd8) == 0)) {
                                        FUN_1801bb8d0();
                                      }
                                      pUVar19 = UnityEngine.Quaternion$$get_identity
                                                          (&tempVecOrQuat1,(MethodInfo *)0x0);
                                      if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
                                        tempVecOrQuat1.fields.x = (pUVar19->fields).x;
                                        tempVecOrQuat1.fields.y = (pUVar19->fields).y;
                                        tempVecOrQuat1.fields.z = (pUVar19->fields).z;
                                        tempVecOrQuat1.fields.w = (pUVar19->fields).w;
                                        UnityEngine.Transform$$set_localRotation
                                                  (pUVar27,&tempVecOrQuat1,(MethodInfo *)0x0);
                                        pSVar8 = (__this->fields).physBody;
                                        if ((pSVar8 != (StressLevelZero_VRMK_PhysBody_o *)0x0) &&
                                           (pUVar26 = StressLevelZero.VRMK.PhysBody$$get_rbKnee
                                                                (pSVar8,(MethodInfo *)0x0),
                                           pUVar26 != (UnityEngine_Rigidbody_o *)0x0)) {
                                          pUVar27 = UnityEngine.Component$$get_transform
                                                              ((UnityEngine_Component_o *)pUVar26,
                                                               (MethodInfo *)0x0);
                                          pUVar19 = UnityEngine.Quaternion$$get_identity
                                                              (&tempVecOrQuat1,(MethodInfo *)0x0);
                                          if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
                                            tempVecOrQuat1.fields.x = (pUVar19->fields).x;
                                            tempVecOrQuat1.fields.y = (pUVar19->fields).y;
                                            tempVecOrQuat1.fields.z = (pUVar19->fields).z;
                                            tempVecOrQuat1.fields.w = (pUVar19->fields).w;
                                            UnityEngine.Transform$$set_localRotation
                                                      (pUVar27,&tempVecOrQuat1,(MethodInfo *)0x0);
                                            if ((__this->fields)._ballLocoEnabled == false) {
                                              return;
                                            }
                                            pSVar8 = (__this->fields).physBody;
                                            if (pSVar8 != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
                                              StressLevelZero.VRMK.PhysBody$$SetBodyMassDistribution
                                                        (pSVar8,(MethodInfo *)0x0);
                                              pUVar27 = (prevRig->fields).m_pelvis;
                                              pSVar8 = (__this->fields).physBody;
                                              if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
                                                pUVar23 = UnityEngine.Transform$$get_localPosition
                                                                    ((UnityEngine_Vector3_o *)
                                                                     &tempVecOrQuat2,pUVar27,
                                                                     (MethodInfo *)0x0);
                                                tempVecOrQuat1.fields.x = (pUVar23->fields).x;
                                                tempVecOrQuat1.fields.y = (pUVar23->fields).y;
                                                tempVecOrQuat1.fields.z = (pUVar23->fields).z;
                                                if (pSVar8 != (StressLevelZero_VRMK_PhysBody_o *)0x0
                                                   ) {
                                                  StressLevelZero.VRMK.PhysBody$$UpdateKnee
                                                            (pSVar8,tempVecOrQuat1.fields.y,
                                                             (MethodInfo *)0x0);
                                                  pUVar27 = (prevRig->fields).m_head;
                                                  pSVar8 = (__this->fields).physBody;
                                                  if (pUVar27 != (UnityEngine_Transform_o *)0x0) {
                                                    pUVar23 = UnityEngine.Transform$$get_position
                                                                        ((UnityEngine_Vector3_o *)
                                                                         &tempVecOrQuat1,pUVar27,
                                                                         (MethodInfo *)0x0);
                                                    uVar5._0_4_ = (pUVar23->fields).x;
                                                    uVar5._4_4_ = (pUVar23->fields).y;
                                                    tempVec1Z = (pUVar23->fields).z;
                                                    if (((*(byte *)(UnityEngine.Vector3_TypeInfo +
                                                                   0x127) & 2) != 0) &&
                                                       (*(int *)(UnityEngine.Vector3_TypeInfo + 0xd8
                                                                ) == 0)) {
                                                      FUN_1801bb8d0();
                                                    }
                                                    tempVecOrQuat2.fields._0_8_ = uVar5;
                                                    tempVecOrQuat2.fields.z = tempVec1Z;
                                                    tempVecOrQuat1.fields._0_8_ = tempVec22XY;
                                                    tempVecOrQuat1.fields.z = tempVec2Z;
                                                    pUVar23 = UnityEngine.Vector3$$op_Subtraction
                                                                        ((UnityEngine_Vector3_o *)
                                                                         &tempVecOrQuat3,
                                                                         (UnityEngine_Vector3_o *)
                                                                         &tempVecOrQuat2,
                                                                         (UnityEngine_Vector3_o *)
                                                                         &tempVecOrQuat1,
                                                                         (MethodInfo *)0x0);
                                                    uVar6._0_4_ = (pUVar23->fields).x;
                                                    uVar6._4_4_ = (pUVar23->fields).y;
                                                    tempVec1Z = (pUVar23->fields).z;
                                                    fixedDeltaTime =
                                                         UnityEngine.Time$$get_fixedDeltaTime
                                                                   ((MethodInfo *)0x0);
                                                    tempVecOrQuat1.fields._0_8_ = uVar6;
                                                    tempVecOrQuat1.fields.z = tempVec1Z;
                                                    pUVar23 = UnityEngine.Vector3$$op_Division
                                                                        ((UnityEngine_Vector3_o *)
                                                                         &tempVecOrQuat2,
                                                                         (UnityEngine_Vector3_o *)
                                                                         &tempVecOrQuat1,
                                                                         fixedDeltaTime,
                                                                         (MethodInfo *)0x0);
                                                    if (pSVar8 != (StressLevelZero_VRMK_PhysBody_o *
                                                                  )0x0) {
                                                      tempVecOrQuat1.fields.x = (pUVar23->fields).x;
                                                      tempVecOrQuat1.fields.y = (pUVar23->fields).y;
                                                      tempVecOrQuat1.fields.z = (pUVar23->fields).z;
                                                      StressLevelZero.VRMK.PhysBody$$ApplyForce
                                                                (pSVar8,(UnityEngine_Vector3_o *)
                                                                        &tempVecOrQuat1,
                                                                 (MethodInfo *)0x0);
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
LAB_1804309fe:
                    /* WARNING: Subroutine does not return */
  ThrowNullReferenceException();
}

