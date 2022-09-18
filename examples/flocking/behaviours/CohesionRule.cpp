#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce = Vector2(0,0);

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood
    if(neighborhood.size() > 0)
    {
        for(auto boid : neighborhood)
        {
            cohesionForce += boid->getPosition();
        }

        cohesionForce = (cohesionForce / neighborhood.size()) - boid->getPosition();
    }

    return cohesionForce.normalized();
}