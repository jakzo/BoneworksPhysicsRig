using System;
using System.Collections;
using System.Collections.Generic;
using StressLevelZero;
using UnityEngine;

namespace BoneworksMovement {
static class Layers {
  // public static int DEFAULT = LayerMask.NameToLayer("Default");
  public const int DEFAULT = 0; // must be constant to be used as default
  public static int PLAYER = LayerMask.NameToLayer("Player");
  public static int HAND = LayerMask.NameToLayer("Hand");
  public static int FEET = LayerMask.NameToLayer("Feet");
  public static int INTERACTABLE_ONLY = LayerMask.NameToLayer("InteractableOnly");
  public static int DYNAMIC = LayerMask.NameToLayer("Dynamic");
}

public class BwPhysicsRig : MonoBehaviour {

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

      var palm = CreateGameObject("PalmCenter", parent: hand.transform, layer: Layers.HAND);

      var fingers = CreateGameObject($"{handednessText[0]}_fingers_col", parent: hand.transform, layer: Layers.HAND, onCreated: obj => {
        // TODO: BoxCollider
      });

      var forearm = CreateGameObject($"{handednessText[0]}_foreArm_col", parent: hand.transform, layer: Layers.HAND, onCreated: obj => {
        // TODO: CapsuleCollider
      });

      var inventoryCapsule = CreateGameObject("Inventory", parent: hand.transform, layer: Layers.INTERACTABLE_ONLY, onCreated: obj => {
        // TODO: CapsuleCollider
      });

      var inventorySphere = CreateGameObject("Inventory", parent: hand.transform, layer: Layers.INTERACTABLE_ONLY, onCreated: obj => {
        // TODO: SphereCollider
      });
    }

    var pelvis = CreateGameObject("Pelvis", parent: transform, layer: Layers.DEFAULT, onCreated: obj => {
      // TODO: Rigidbody
      // TODO: PhysBody
      // TODO: PlayerDamageReceiver
      // TODO: PlayerTriggerProxy

      var chest = CreateGameObject("Chest", parent: transform, layer: Layers.PLAYER, onCreated: obj2 => {
        // TODO: CapsuleCollider
        // TODO: BoxCollider

        var trigger = CreateGameObject("ChestTriggerProxy", parent: transform, layer: Layers.PLAYER);
      });

      var collider = CreateGameObject("pelvisCol", parent: transform, layer: Layers.PLAYER, onCreated: obj2 => {
        // TODO: CapsuleCollider
      });

      var resetHandLeft = CreateGameObject("Reset Hand (left)", parent: transform, layer: Layers.DEFAULT);
      var resetHandRight = CreateGameObject("Reset Hand (right)", parent: transform, layer: Layers.DEFAULT);
    });

    var knee = CreateGameObject("Knee", parent: transform, layer: Layers.FEET, onCreated: obj => {
      // TODO: SphereCollider
      // TODO: Rigidbody
      // TODO: ConfigurableJoint
      // TODO: PlayerTriggerProxy
      // TODO: PlayerDamageReceiver

      var kneeToPelvis = CreateGameObject("KneeToPelvis", parent: transform, layer: Layers.FEET, onCreated: obj2 => {
        // TODO: CapsuleCollider
      });
    });

    var feet = CreateGameObject("Feet", parent: transform, layer: Layers.FEET, onCreated: obj => {
      // TODO: SphereCollider
      // TODO: Rigidbody
      // TODO: ConfigurableJoint
      // TODO: PhysGrounder
      // TODO: PlayerTriggerProxy
      // TODO: PlayerDamageReceiver
    });

    foreach (var handedness in new[] { Handedness.RIGHT, Handedness.LEFT }) {
      var handednessText = handedness == Handedness.LEFT ? "left" : "right";
      var foot = CreateGameObject($"Foot ({handednessText})", parent: transform, layer: Layers.DYNAMIC);
    }
  }

  public void OnFixedUpdate(float deltaTime) {
    _lastHeadPos = m_head.position;
    var prevRig = manager.rigs[(rigIndex == 0 ? manager.rigs.Length : rigIndex) - 1];
    var nearPelvisLocalPos = new Vector3(0f, m_pelvis.localPosition.y, -0.04f);
    var nearPelvisPos = prevRig.transform.TransformPoint(nearPelvisLocalPos);
    var pelvisAtHeadHeight = m_pelvis.position + (m_head.position - nearPelvisPos);
    var pelvisAtHeadHeightLocalPos = m_pelvis.InverseTransformPoint(pelvisAtHeadHeight);
    torso.h
  }

  GameObject CreateGameObject(string name, Transform parent = null, int layer = Layers.DEFAULT, Action<GameObject> onCreated = null) {
    var obj = new GameObject(name) { layer = layer };
    obj.transform.SetParent(parent, false);
    onCreated?.Invoke(obj);
    return obj;
  }
}
}
