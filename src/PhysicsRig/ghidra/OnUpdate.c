
void StressLevelZero_Rig_PhysicsRig__OnUpdate
               (StressLevelZero_Rig_PhysicsRig_o *__this,MethodInfo *method)

{
  UnityEngine_Transform_o *gameWorldSkelTransform;
  UnityEngine_Rigidbody_o *rbFeet;
  UnityEngine_Vector3_o *feetPos;
  UnityEngine_Vector3_o *footFloorPos;
  UnityEngine_Transform_o *realSkelTransform;
  UnityEngine_Quaternion_o *realSkelRot;
  StressLevelZero_Rig_BaseController_o *leftController;
  StressLevelZero_Rig_BaseController_o *rightController;
  StressLevelZero_VRMK_SLZ_Body_o *realSkelBody;
  float lfCurl;
  float rtCurl;
  UnityEngine_Vector3_o topOfFootBall;
  UnityEngine_Vector3_o topOfFootBall2;
  UnityEngine_Vector3_o tempVec1;
  UnityEngine_Quaternion_o tempVecOrQuat;
  StressLevelZero_VRMK_PhysBody_o *physBody;
  float feetZ;
  StressLevelZero_VRMK_PhysBody_o *physBody2;
  StressLevelZero_Rig_RigManager_o *rigManager;
  StressLevelZero_Rig_SkeletonRig_o *gameWorldSkelRig;
  StressLevelZero_Interaction_Hand_o *leftHand;
  StressLevelZero_Interaction_Hand_o *rightHand;
  StressLevelZero_Interaction_Hand_o *leftHand2;
  float footFloorZ;
  StressLevelZero_Rig_SkeletonRig_o *realSkelRig;
  StressLevelZero_Rig_RigManager_o *rigManager2;
  undefined8 feetXY;
  undefined8 footFloorXY;
  StressLevelZero_VRMK_PhysBody_o *physBody3;
  StressLevelZero_Rig_SkeletonRig_o *realSkelRig2;
  StressLevelZero_Rig_RigManager_o *rigManager3;
  StressLevelZero_Interaction_Hand_o *rightHand2;
  
  if (DAT_181ebb179 == '\0') {
    FUN_1801ad630(0x6025);
    DAT_181ebb179 = '\x01';
  }
  rigManager = (__this->fields).field0_0x0.manager;
  if ((rigManager != (StressLevelZero_Rig_RigManager_o *)0x0) &&
     (gameWorldSkelRig = (rigManager->fields).gameWorldSkeletonRig,
     gameWorldSkelRig != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) {
    gameWorldSkelTransform =
         UnityEngine_Component__get_transform
                   ((UnityEngine_Component_o *)gameWorldSkelRig,(MethodInfo *)0x0);
    physBody = (__this->fields).physBody;
    if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
      rbFeet = StressLevelZero_VRMK_PhysBody__get_rbFeet(physBody,(MethodInfo *)0x0);
      if (rbFeet != (UnityEngine_Rigidbody_o *)0x0) {
        feetPos = UnityEngine_Rigidbody__get_position(&tempVec1,rbFeet,(MethodInfo *)0x0);
        feetXY._0_4_ = (feetPos->fields).x;
        feetXY._4_4_ = (feetPos->fields).y;
        feetZ = (feetPos->fields).z;
        physBody2 = (__this->fields).physBody;
        if (physBody2 != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
          topOfFootBall.fields.x = 0.0;
          topOfFootBall.fields.y = 0.0;
          topOfFootBall.fields.z = 0.0;
          UnityEngine_Vector3__Set(&topOfFootBall,0.0,(physBody2->fields).footballRadius,0.0);
          if (((*(byte *)(UnityEngine_Vector3_TypeInfo + 0x127) & 2) != 0) &&
             (*(int *)(UnityEngine_Vector3_TypeInfo + 0xd8) == 0)) {
            FUN_1801bb8d0();
          }
          topOfFootBall2.fields.x = topOfFootBall.fields.x;
          topOfFootBall2.fields.y = topOfFootBall.fields.y;
          topOfFootBall2.fields.z = topOfFootBall.fields.z;
          tempVec1.fields._0_8_ = feetXY;
          tempVec1.fields.z = feetZ;
          footFloorPos = UnityEngine_Vector3__op_Subtraction
                                   ((UnityEngine_Vector3_o *)&tempVecOrQuat,&tempVec1,
                                    &topOfFootBall2,(MethodInfo *)0x0);
          rigManager2 = (__this->fields).field0_0x0.manager;
          footFloorXY._0_4_ = (footFloorPos->fields).x;
          footFloorXY._4_4_ = (footFloorPos->fields).y;
          footFloorZ = (footFloorPos->fields).z;
          if ((rigManager2 != (StressLevelZero_Rig_RigManager_o *)0x0) &&
             (realSkelRig = (rigManager2->fields).realtimeSkeletonRig,
             realSkelRig != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) {
            realSkelTransform =
                 UnityEngine_Component__get_transform
                           ((UnityEngine_Component_o *)realSkelRig,(MethodInfo *)0x0);
            if (realSkelTransform != (UnityEngine_Transform_o *)0x0) {
              realSkelRot = UnityEngine_Transform__get_rotation
                                      (&tempVecOrQuat,realSkelTransform,(MethodInfo *)0x0);
              if (gameWorldSkelTransform != (UnityEngine_Transform_o *)0x0) {
                tempVecOrQuat.fields.x = (realSkelRot->fields).x;
                tempVecOrQuat.fields.y = (realSkelRot->fields).y;
                tempVecOrQuat.fields.z = (realSkelRot->fields).z;
                tempVecOrQuat.fields.w = (realSkelRot->fields).w;
                tempVec1.fields._0_8_ = footFloorXY;
                tempVec1.fields.z = footFloorZ;
                UnityEngine_Transform__SetPositionAndRotation
                          (gameWorldSkelTransform,&tempVec1,&tempVecOrQuat,(MethodInfo *)0x0);
                UnityEngine_Physics__SyncTransforms((MethodInfo *)0x0);
                leftHand = (__this->fields).leftHand;
                if (leftHand != (StressLevelZero_Interaction_Hand_o *)0x0) {
                  StressLevelZero_Interaction_Hand__OrderedUpdate(leftHand,(MethodInfo *)0x0);
                  rightHand = (__this->fields).rightHand;
                  if (rightHand != (StressLevelZero_Interaction_Hand_o *)0x0) {
                    StressLevelZero_Interaction_Hand__OrderedUpdate(rightHand,(MethodInfo *)0x0);
                    leftHand2 = (__this->fields).leftHand;
                    physBody3 = (__this->fields).physBody;
                    if (leftHand2 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                      leftController =
                           StressLevelZero_Interaction_Hand__get_controller
                                     (leftHand2,(MethodInfo *)0x0);
                      if (leftController != (StressLevelZero_Rig_BaseController_o *)0x0) {
                        lfCurl = (float)(*(leftController->klass->vtable).
                                          _19_GetSecondaryInteractionButtonAxis.methodPtr)
                                                  (leftController);
                        rightHand2 = (__this->fields).rightHand;
                        if (rightHand2 != (StressLevelZero_Interaction_Hand_o *)0x0) {
                          rightController =
                               StressLevelZero_Interaction_Hand__get_controller
                                         (rightHand2,(MethodInfo *)0x0);
                          if (rightController != (StressLevelZero_Rig_BaseController_o *)0x0) {
                            rtCurl = (float)(*(rightController->klass->vtable).
                                              _19_GetSecondaryInteractionButtonAxis.methodPtr)
                                                      (rightController);
                            rigManager3 = (__this->fields).field0_0x0.manager;
                            if ((rigManager3 != (StressLevelZero_Rig_RigManager_o *)0x0) &&
                               (realSkelRig2 = (rigManager3->fields).realtimeSkeletonRig,
                               realSkelRig2 != (StressLevelZero_Rig_SkeletonRig_o *)0x0)) {
                              realSkelBody = StressLevelZero_Rig_SkeletonRig__get_body
                                                       (realSkelRig2,(MethodInfo *)0x0);
                              if ((realSkelBody != (StressLevelZero_VRMK_SLZ_Body_o *)0x0) &&
                                 (physBody3 != (StressLevelZero_VRMK_PhysBody_o *)0x0)) {
                                StressLevelZero_VRMK_PhysBody__UpdateColliders
                                          (physBody3,lfCurl,rtCurl,
                                           &(realSkelBody->fields).references,(MethodInfo *)0x0);
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
                    /* WARNING: Subroutine does not return */
  ThrowNullReferenceException();
}

