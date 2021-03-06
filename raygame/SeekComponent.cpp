#include "SeekComponent.h"
#include "Actor.h"
#include "Agent.h"
#include "MoveComponent.h"
#include "Transform2D.h"



MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	setSteeringForce(500);

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition()
		- getOwner()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();
	return seekForce;
}