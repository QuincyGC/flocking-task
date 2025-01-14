#include "BoundedAreaRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 BoundedAreaRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Return a force proportional to the proximity of the boids with the bounds, and opposed to it
    Vector2 force = Vector2::zero(); //zero
    //this->world->engine->window->size().x;

    // todo: add here your code code here do make the boid follow the bounded box rule
    // hint: use this->world->engine->window->size() and desiredDistance

    //four edges of the ascreen vertical and horizantal x y
    //bottom of screen is screen height  right screen width
    // top 0 y
    //left 0 x
    //left and right check the x of the boid add desired\distance ti  left size force is positive in x direction
    //force.x equals one
    //screen width  - desired distance < boids pos. x force.x = -1

    if(desiredDistance > boid->getPosition().x)
    {
        force.x = 1;
    }
    if((this->world->engine->window->size().x - desiredDistance) < boid->getPosition().x)
    {
        force.x = -1;
    }
    if((this->world->engine->window->size().y - desiredDistance) < boid->getPosition().y)
    {
        force.y = -1 ;
    }
    if(desiredDistance > boid->getPosition().y)
    {
        force.y = 1;
    }

    return force;
}

bool BoundedAreaRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    auto size = this->world->engine->window->size();
    auto widthWindows = size.x;
    auto heightWindows = size.y;
    bool valueHasChanged = false;

    //We cap the max separation as the third of the min of the width.height
    auto minHeightWidth = std::min(widthWindows, heightWindows);

    if (ImGui::SliderInt("Desired Distance From Borders",
                         &desiredDistance,
                         0.0f,
                         (int)(minHeightWidth/3),
                         "%i")) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}

void BoundedAreaRule::draw(const Boid& boid, SDL_Renderer* renderer) const {
    FlockingRule::draw(boid, renderer);
    auto size = this->world->engine->window->size();
    auto dist = (float)desiredDistance;

    // Draw a rectangle on the map
    Polygon::DrawLine(renderer, Vector2(dist,dist), Vector2(size.x - dist,dist), Vector3::Gray()); // TOP
    Polygon::DrawLine(renderer, Vector2(size.x - dist,dist), Vector2(size.x - dist,size.y - dist), Vector3::Gray()); // RIGHT
    Polygon::DrawLine(renderer, Vector2(size.x - dist,size.y - dist), Vector2(dist,size.y - dist), Vector3::Gray()); // Bottom
    Polygon::DrawLine(renderer, Vector2(dist,size.y - dist), Vector2(dist,dist), Vector3::Gray()); // LEFT
}