
void StressLevelZero_VRMK_PhysHand__ReadSensors
               (StressLevelZero_VRMK_PhysHand_o *__this,UnityEngine_ConfigurableJoint_o *joint,
               float *divByNewtons,MethodInfo *method)

{
  bool hasJoint;
  UnityEngine_Vector3_o *jointCurrentForce;
  float fixedDeltaTime;
  float fixedDeltaTime2;
  float newHandSupported;
  float exertedForceY;
  float handSpeed;
  float jointForceY;
  UnityEngine_Vector3_o tempVec [5];
  float divByNewtons2;
  float handSupported;
  undefined8 joinCurrentForceXY;
  
  if (DAT_181ec3498 == '\0') {
    FUN_1801ad630(0x5fae);
    DAT_181ec3498 = '\x01';
  }
  jointForceY = (__this->fields)._collisionImpulse.fields.y;
  if (((*(byte *)(UnityEngine_Object_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine_Object_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  hasJoint = UnityEngine_Object__op_Inequality
                       ((UnityEngine_Object_o *)joint,(UnityEngine_Object_o *)0x0,(MethodInfo *)0x0)
  ;
  if (hasJoint) {
    if ((__this->fields).handPhysState - 3U < 2) {
      exertedForceY = (float)((uint)(__this->fields).appliedForce.fields.y ^ 0x80000000);
    }
    else {
      if (joint == (UnityEngine_ConfigurableJoint_o *)0x0) {
                    /* WARNING: Subroutine does not return */
        ThrowNullReferenceException();
      }
      jointCurrentForce =
           UnityEngine_Joint__get_currentForce
                     (tempVec,(UnityEngine_Joint_o *)joint,(MethodInfo *)0x0);
      joinCurrentForceXY._0_4_ = (jointCurrentForce->fields).x;
      joinCurrentForceXY._4_4_ = (jointCurrentForce->fields).y;
      exertedForceY = (float)((ulonglong)joinCurrentForceXY >> 32);
    }
    fixedDeltaTime = UnityEngine_Time__get_fixedDeltaTime((MethodInfo *)0x0);
    jointForceY = jointForceY + fixedDeltaTime * exertedForceY;
  }
  divByNewtons2 = *divByNewtons;
  handSupported = (__this->fields).handSupported;
  fixedDeltaTime2 = UnityEngine_Time__get_fixedDeltaTime((MethodInfo *)0x0);
  if (jointForceY * divByNewtons2 <= handSupported) {
    handSpeed = fixedDeltaTime2 * 4.0;
  }
  else {
    handSpeed = fixedDeltaTime2 * 8.0;
  }
  if (((*(byte *)(UnityEngine_Mathf_TypeInfo + 0x127) & 2) != 0) &&
     (*(int *)(UnityEngine_Mathf_TypeInfo + 0xd8) == 0)) {
    FUN_1801bb8d0();
  }
  newHandSupported =
       UnityEngine_Mathf__MoveTowards
                 (handSupported,jointForceY * divByNewtons2,handSpeed,(MethodInfo *)0x0);
  (__this->fields).handSupported = newHandSupported;
  StressLevelZero_VRMK_PhysHand__CheckStuck(__this,*divByNewtons,(MethodInfo *)0x0);
  return;
}

