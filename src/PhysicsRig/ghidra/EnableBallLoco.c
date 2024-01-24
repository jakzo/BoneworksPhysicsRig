
void StressLevelZero_Rig_PhysicsRig__EnableBallLoco
               (StressLevelZero_Rig_PhysicsRig_o *__this,MethodInfo *method)

{
  UnityEngine_Rigidbody_o *rbFeet;
  UnityEngine_Rigidbody_o *rbKnee;
  StressLevelZero_VRMK_PhysBody_o *physBody;
  
  (__this->fields)._ballLocoEnabled = true;
  physBody = (__this->fields).physBody;
  if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
    rbFeet = StressLevelZero_VRMK_PhysBody__get_rbFeet(physBody,(MethodInfo *)0x0);
    if (rbFeet != (UnityEngine_Rigidbody_o *)0x0) {
      UnityEngine_Rigidbody__set_detectCollisions(rbFeet,true,(MethodInfo *)0x0);
      physBody = (__this->fields).physBody;
      if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
        rbKnee = StressLevelZero_VRMK_PhysBody__get_rbKnee(physBody,(MethodInfo *)0x0);
        if (rbKnee != (UnityEngine_Rigidbody_o *)0x0) {
          UnityEngine_Rigidbody__set_detectCollisions(rbKnee,true,(MethodInfo *)0x0);
          physBody = (__this->fields).physBody;
          if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
            (physBody->fields).footballRadius = 0.18;
            physBody = (__this->fields).physBody;
            if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
              (physBody->fields).bodyMassNaturalHold = false;
              physBody = (__this->fields).physBody;
              if (physBody != (StressLevelZero_VRMK_PhysBody_o *)0x0) {
                StressLevelZero_VRMK_PhysBody__SetBodyMassDistribution(physBody,(MethodInfo *)0x0);
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

