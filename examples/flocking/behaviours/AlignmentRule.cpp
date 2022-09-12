#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid)
{
    Vector2 averageVelocity = Vector2::zero();

    for (auto boid : neighborhood) {
        //auto automatic typing
        //foreach is better for pointers
        //foreach creates a copy if not a pointer
        //Jason Turner Youtube

        averageVelocity.x += boid->velocity.x;
        averageVelocity.y += boid->velocity.y;
    }

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood

    return Vector2::normalized(averageVelocity);
}