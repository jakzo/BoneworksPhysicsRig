
void StressLevelZero_Rig_PhysicsRig__OnStart
               (StressLevelZero_Rig_PhysicsRig_o *__this,MethodInfo *method)

{
  uint prevRigIdx;
  StressLevelZero_VRMK_SLZ_Body_o *gameSkelBody;
  UnityEngine_Vector3_o *leftHandPos;
  UnityEngine_Quaternion_o *leftHandRot;
  UnityEngine_Vector3_o *rightHandPos;
  UnityEngine_Quaternion_o *rightHandRot;
  longlong ex;
  UnityEngine_Vector3_o tempVec1;
  UnityEngine_Quaternion_o tempQuat1;
  StressLevelZero_Interaction_Hand_o *leftHand2;
  StressLevelZero_VRMK_PhysHand_o *leftPhysHand2;
  StressLevelZero_VRMK_PhysHand_o *leftPhysHand;
  StressLevelZero_Interaction_Hand_o *rightHand;
  StressLevelZero_VRMK_PhysHand_o *rightPhysHand;
  StressLevelZero_Interaction_Hand_o *leftHand3;
  StressLevelZero_VRMK_PhysHand_o *leftPhysHand3;
  StressLevelZero_Interaction_Hand_o *leftHand;
  StressLevelZero_Rig_RigManager_o *rigManager;
  StressLevelZero_VRMK_PhysHand_o *leftPhysHand4;
  UnityEngine_Transform_o *m_leftHand;
  StressLevelZero_Interaction_Hand_o *leftHand4;
  UnityEngine_Transform_o *m_leftHand2;
  StressLevelZero_Interaction_Hand_o *rightHand3;
  StressLevelZero_VRMK_PhysHand_o *rightPhysHand3;
  StressLevelZero_Interaction_Hand_o *rightHand2;
  StressLevelZero_VRMK_PhysHand_o *rightPhysHand2;
  UnityEngine_Transform_o *m_rightHand;
  float leftHandZ;
  StressLevelZero_VRMK_SLZ_Body_References_o *bodyRefs;
  StressLevelZero_Rig_SkeletonRig_o *gameSkelRig;
  undefined8 leftHandXY;
  UnityEngine_Transform_o *m_rightHand2;
  StressLevelZero_VRMK_PhysBody_o *physBody;
  StressLevelZero_Rig_Rig_o *prevRig;
  StressLevelZero_Rig_RigManager_o *rigManager2;
  StressLevelZero_Interaction_Hand_o *rightHand4;
  undefined8 rightHandXY;
  float rightHandZ;
  StressLevelZero_VRMK_PhysHand_o *rightPhysHand4;
  StressLevelZero_Rig_Rig_array *rigs;
  
  rigManager = (__this->fields).field0_0x0.manager;
  if ((rigManager != (StressLevelZero_Rig_RigManager_o *)0x0) &&
     (gameSkelRig = (rigManager->fields).gameWorldSkeletonRig,
     gameSkelRig != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) {
    gameSkelBody = StressLevelZero_Rig_SkeletonRig__get_body(gameSkelRig,(MethodInfo *)0x0);
    if ((gameSkelBody != (StressLevelZero_VRMK_SLZ_Body_o *)0x0) &&
       (((leftHand = (__this->fields).leftHand,
         leftHand != (StressLevelZero_Interaction_Hand_o *)0x0 &&
         (bodyRefs = (gameSkelBody->fields).references,
         bodyRefs != (StressLevelZero_VRMK_SLZ_Body_References_o *)0x0)) &&
        (leftPhysHand = (leftHand->fields).physHand,
        leftPhysHand != (StressLevelZero_VRMK_PhysHand_o *)0x0)))) {
      (leftPhysHand->fields).t1Vert = (bodyRefs->fields).c4Vertebra;
      leftHand2 = (__this->fields).leftHand;
      if ((leftHand2 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
         (leftPhysHand2 = (leftHand2->fields).physHand,
         leftPhysHand2 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
        (leftPhysHand2->fields).shoulder = (bodyRefs->fields).rtScapula;
        leftHand3 = (__this->fields).leftHand;
        if ((leftHand3 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
           (leftPhysHand3 = (leftHand3->fields).physHand,
           leftPhysHand3 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
          (leftPhysHand3->fields).wrist = (bodyRefs->fields).rightElbow;
          rightHand = (__this->fields).rightHand;
          if ((rightHand != (StressLevelZero_Interaction_Hand_o *)0x0) &&
             (rightPhysHand = (rightHand->fields).physHand,
             rightPhysHand != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
            (rightPhysHand->fields).t1Vert = (bodyRefs->fields).c4Vertebra;
            rightHand2 = (__this->fields).rightHand;
            if ((rightHand2 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
               (rightPhysHand2 = (rightHand2->fields).physHand,
               rightPhysHand2 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
              (rightPhysHand2->fields).shoulder = (bodyRefs->fields).leftShoulder;
              rightHand3 = (__this->fields).rightHand;
              if ((rightHand3 != (StressLevelZero_Interaction_Hand_o *)0x0) &&
                 (rightPhysHand3 = (rightHand3->fields).physHand,
                 rightPhysHand3 != (StressLevelZero_VRMK_PhysHand_o *)0x0)) {
                (rightPhysHand3->fields).wrist = (bodyRefs->fields).leftWrist;
                rigManager2 = (__this->fields).field0_0x0.manager;
                if ((rigManager2 != (StressLevelZero_Rig_RigManager_o *)0x0) &&
                   (rigs = (rigManager2->fields).rigs, rigs != (StressLevelZero_Rig_Rig_array *)0x0)
                   ) {
                  prevRigIdx = StressLevelZero_Utils__Mod
                                         ((__this->fields).field0_0x0.rigIndex + -1,
                                          *(int32_t *)&rigs->max_length,(MethodInfo *)0x0);
                  if (*(uint *)&rigs->max_length <= prevRigIdx) {
                    ex = IndexOutOfRangeException();
                    /* WARNING: Subroutine does not return */
                    ThrowException(ex);
                  }
                  leftHand4 = (__this->fields).leftHand;
                  if (leftHand4 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                    prevRig = rigs->m_Items[(int)prevRigIdx];
                    leftPhysHand4 = (leftHand4->fields).physHand;
                    if ((prevRig != (StressLevelZero_Rig_Rig_o *)0x0) &&
                       (m_leftHand = (prevRig->fields).m_leftHand,
                       m_leftHand != (UnityEngine_Transform_o *)0x0)) {
                      leftHandPos = UnityEngine_Transform__get_position
                                              (&tempVec1,m_leftHand,(MethodInfo *)0x0);
                      m_leftHand2 = (prevRig->fields).m_leftHand;
                      leftHandXY._0_4_ = (leftHandPos->fields).x;
                      leftHandXY._4_4_ = (leftHandPos->fields).y;
                      leftHandZ = (leftHandPos->fields).z;
                      if (m_leftHand2 != (UnityEngine_Transform_o *)0x0) {
                        leftHandRot = UnityEngine_Transform__get_rotation
                                                (&tempQuat1,m_leftHand2,(MethodInfo *)0x0);
                        if (leftPhysHand4 != (StressLevelZero_VRMK_PhysHand_o *)0x0) {
                          tempQuat1.fields.x = (leftHandRot->fields).x;
                          tempQuat1.fields.y = (leftHandRot->fields).y;
                          tempQuat1.fields.z = (leftHandRot->fields).z;
                          tempQuat1.fields.w = (leftHandRot->fields).w;
                          tempVec1.fields._0_8_ = leftHandXY;
                          tempVec1.fields.z = leftHandZ;
                          StressLevelZero_VRMK_PhysHand__SetHand
                                    (leftPhysHand4,&tempVec1,&tempQuat1,true,(MethodInfo *)0x0);
                          rightHand4 = (__this->fields).rightHand;
                          if (rightHand4 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                            m_rightHand = (prevRig->fields).m_rightHand;
                            rightPhysHand4 = (rightHand4->fields).physHand;
                            if (m_rightHand != (UnityEngine_Transform_o *)0x0) {
                              rightHandPos = UnityEngine_Transform__get_position
                                                       (&tempVec1,m_rightHand,(MethodInfo *)0x0);
                              m_rightHand2 = (prevRig->fields).m_rightHand;
                              rightHandXY._0_4_ = (rightHandPos->fields).x;
                              rightHandXY._4_4_ = (rightHandPos->fields).y;
                              rightHandZ = (rightHandPos->fields).z;
                              if (m_rightHand2 != (UnityEngine_Transform_o *)0x0) {
                                rightHandRot = UnityEngine_Transform__get_rotation
                                                         (&tempQuat1,m_rightHand2,(MethodInfo *)0x0)
                                ;
                                if (rightPhysHand4 != (StressLevelZero_VRMK_PhysHand_o *)0x0) {
                                  tempQuat1.fields.x = (rightHandRot->fields).x;
                                  tempQuat1.fields.y = (rightHandRot->fields).y;
                                  tempQuat1.fields.z = (rightHandRot->fields).z;
                                  tempQuat1.fields.w = (rightHandRot->fields).w;
                                  tempVec1.fields._0_8_ = rightHandXY;
                                  tempVec1.fields.z = rightHandZ;
                                  StressLevelZero_VRMK_PhysHand__SetHand
                                            (rightPhysHand4,&tempVec1,&tempQuat1,true,
                                             (MethodInfo *)0x0);
                                  physBody = (__this->fields).physBody;
                                  if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180430ccd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                                    (*(physBody->klass->vtable)._5_OnStart.methodPtr)
                                              (physBody,(physBody->klass->vtable)._5_OnStart.method)
                                    ;
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
                    /* WARNING: Subroutine does not return */
  ThrowNullReferenceException();
}

