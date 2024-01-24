
void StressLevelZero_Rig_PhysicsRig__OnAwake
               (StressLevelZero_Rig_PhysicsRig_o *__this,MethodInfo *method)

{
  StressLevelZero_Interaction_Hand_o *leftHand;
  StressLevelZero_Interaction_Hand_o *rightHand;
  StressLevelZero_VRMK_PhysBody_o *physBody;
  UnityEngine_Rigidbody_o *rbPelvis;
  UnityEngine_Quaternion_o *pelvisRot;
  UnityEngine_Quaternion_o tempQuat;
  UnityEngine_Transform_o *m_leftHand;
  StressLevelZero_Interaction_Hand_o *leftHand2;
  UnityEngine_Transform_o *m_rightHand;
  float pelvisRotW;
  float pelvisRotX;
  float pelvisRotY;
  float pelvisRotZ;
  StressLevelZero_VRMK_PhysBody_o *physBody2;
  
  if (DAT_181ebb178 == '\0') {
    FUN_1801ad630(0x6023);
    DAT_181ebb178 = '\x01';
  }
  m_leftHand = (__this->fields).field0_0x0.m_leftHand;
  if (m_leftHand != (UnityEngine_Transform_o *)0x0) {
    leftHand = (StressLevelZero_Interaction_Hand_o *)
               UnityEngine_Component__GetComponent<GUILayer>
                         ((UnityEngine_Component_o *)m_leftHand,
                          Method_UnityEngine_Component_GetComponent<Hand>__);
    m_rightHand = (__this->fields).field0_0x0.m_rightHand;
    (__this->fields).leftHand = leftHand;
    if (m_rightHand != (UnityEngine_Transform_o *)0x0) {
      rightHand = (StressLevelZero_Interaction_Hand_o *)
                  UnityEngine_Component__GetComponent<GUILayer>
                            ((UnityEngine_Component_o *)m_rightHand,
                             Method_UnityEngine_Component_GetComponent<Hand>__);
      leftHand2 = (__this->fields).leftHand;
      (__this->fields).rightHand = rightHand;
      if (leftHand2 != (StressLevelZero_Interaction_Hand_o *)0x0) {
        StressLevelZero_Interaction_Hand__SetManger
                  (leftHand2,(__this->fields).field0_0x0.manager,(MethodInfo *)0x0);
        rightHand = (__this->fields).rightHand;
        if (rightHand != (StressLevelZero_Interaction_Hand_o *)0x0) {
          StressLevelZero_Interaction_Hand__SetManger
                    (rightHand,(__this->fields).field0_0x0.manager,(MethodInfo *)0x0);
          physBody = (StressLevelZero_VRMK_PhysBody_o *)
                     UnityEngine_Component__GetComponentInChildren<object>
                               ((UnityEngine_Component_o *)__this,
                                Method_UnityEngine_Component_GetComponentInChildren<PhysBody>__);
          (__this->fields).physBody = physBody;
          if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
            (*(physBody->klass->vtable)._4_OnAwake.methodPtr)(physBody);
            physBody2 = (__this->fields).physBody;
            if (physBody2 != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
              rbPelvis = StressLevelZero_VRMK_PhysBody__get_rbPelvis(physBody2,(MethodInfo *)0x0);
              if (rbPelvis != (UnityEngine_Rigidbody_o *)0x0) {
                pelvisRot = UnityEngine_Rigidbody__get_rotation
                                      (&tempQuat,rbPelvis,(MethodInfo *)0x0);
                pelvisRotX = (pelvisRot->fields).x;
                pelvisRotY = (pelvisRot->fields).y;
                pelvisRotZ = (pelvisRot->fields).z;
                pelvisRotW = (pelvisRot->fields).w;
                (__this->fields)._ballLocoEnabled = true;
                (__this->fields)._initialPelvisRotation.fields.x = pelvisRotX;
                (__this->fields)._initialPelvisRotation.fields.y = pelvisRotY;
                (__this->fields)._initialPelvisRotation.fields.z = pelvisRotZ;
                (__this->fields)._initialPelvisRotation.fields.w = pelvisRotW;
                return;
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

