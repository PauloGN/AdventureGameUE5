# Action/Adventure RPG Game UE5
This game is a third-person project developed to be an Action/Adventure RPG
In this prototype, we are exploring the main game mechanics approaching the RPG style.
The template is a 3D third-person game where players must evolve in level and skill to fight enemies. Game features include floating and moving platforms, pick-ups, hazards, explosives, jumping platforms, melee and ranged combat, and an inventory system.

>Status: Developing ⚠️

#### ✨This action/adventure rpg game will be based on Perfect World game.

### Game Mechanic

#### Floor Switch

Floor Switch has a States category where designers can find exposed control variables and then modify their functionality.
Basically, it consists of a floor that, as soon as the character steps on it, will trigger an action to move a door to open the way.

##### Variables:

+ DoorPlaced It allows the designer to set the door location in the world.
+ DelayDoor It tells how long the door should wait before close automatically
+ FloorSwitch Difines the basic mesh to the floor
+ DoorSwitch Difines the basic mesh to the door


#### Floating Platform

The floating Platform mechanic is based on a symmetric movement: distance times time. The designer can adjust the speed, distance traveled, and delay before swapping to move in the opposite direction.
Variables are exposed in the editor under the category states, subcategory platform;
##### Variables:
+ EndPoint is a vector to set the target position to move to, (it has a special widget control).
+ InterpSpeed is a float that controls how fast the platform interpolates between the start point to the end point.
+ InterpDelayTime is a float that controls how much the platform should wait before starts moving again.

#### Moving Platform

Moving platform, is a type of platform that moves or rotates on any given axis, The designer can adjust the speed, distance traveled, and delay before swapping to move in the opposite direction.Variables are exposed in the editor under the category states, subcategory Movement; The movement does not follow an asymmetric interpolation like the floating platform. Instead, its movement is uniform and has a delay time option controlled by a variable exposed on the editor.
##### Variables:

+ PlatformSpeed is a vector, feeding this vector in any direction (x, y, z) will tell the platform to move in the given path. The higher the value, the higher the speed on the axis. Note: more than one axis can be fed.
+ DistanceToMove is a float, the value fed here tells the platform how far it should go and return to its initial position.
+ RotationVelocity is a vector, feeding this vector in any direction (x, y, z) will tell the platform to rotate around the given Axis. The higher the value, the higher the speed on the axis. Note: more than one axis can be fed.
+ RotatePlatform is a boolean, while true (checked) means the platform should rotate, and false (not checked), means the platform should not rotate regardless of the values fed into the vector RotationVelocity.
+ MovePauseDelayTime is a float, the value tells the platform how long it should wait before starts moving in the opposite direction. (back to the initial position, going back and forth)

#### Item

This is the base class to hold all items functionalities that can be collected or overlapped to apply damage.

##### Derived:
+ PickUp
+ Hazard

#### HUDOverlay

The Overall widget that will contem all the other smaller widgets that will be rendered to the screem during the game.
+ HealthBar
