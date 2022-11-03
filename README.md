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

#### Floating Platform

The floating Platform mechanic is based on a symmetric movement: distance times time. The designer can adjust the speed, distance traveled, and delay before swapping to move in the opposite direction.
Variables are exposed in the editor under the category states, subcategory platform;
##### Variables:
+ The EndPoint is a vector to set the target position to move to, (it has a special widget control).
+ InterpSpeed is a float that controls how fast the platform interpolates between the start point to the end point.
+ InterpDelayTime is a float that controls how much the platform should wait before starts moving again.
