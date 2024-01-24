
void StressLevelZero_Rig_PhysicsRig__DisableBallLoco
               (StressLevelZero_Rig_PhysicsRig_o *__this,MethodInfo *method)

{
  UnityEngine_Rigidbody_o *rbFeet;
  UnityEngine_Rigidbody_o *rbKnee;
  StressLevelZero_VRMK_PhysBody_o *physBody;
  
  (__this->fields)._ballLocoEnabled = false;
  physBody = (__this->fields).physBody;
  if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
    rbFeet = StressLevelZero_VRMK_PhysBody__get_rbFeet(physBody,(MethodInfo *)0x0);
    if (rbFeet != (UnityEngine_Rigidbody_o *)0x0) {
      UnityEngine_Rigidbody__set_detectCollisions(rbFeet,false,(MethodInfo *)0x0);
      physBody = (__this->fields).physBody;
      if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
        rbKnee = StressLevelZero_VRMK_PhysBody__get_rbKnee(physBody,(MethodInfo *)0x0);
        if (rbKnee != (UnityEngine_Rigidbody_o *)0x0) {
          UnityEngine_Rigidbody__set_detectCollisions(rbKnee,false,(MethodInfo *)0x0);
          physBody = (__this->fields).physBody;
          if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
            (physBody->fields).footballRadius = 0.11;
            physBody = (__this->fields).physBody;
            if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
              (physBody->fields).bodyMassNaturalHold = true;
              physBody = (__this->fields).physBody;
              if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
                StressLevelZero_VRMK_PhysBody__SetBodyMassDistribution(physBody,(MethodInfo *)0x0);
                physBody = (__this->fields).physBody;
                if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
                  StressLevelZero_VRMK_PhysBody__UpdateKnee(physBody,0.0,(MethodInfo *)0x0);
                  return;
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

