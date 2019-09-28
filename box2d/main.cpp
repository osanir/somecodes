#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#define SCALE 30.f
using namespace std;
using namespace sf;

void createGround(b2World& world, float x, float y);
void createBox(b2World& world, int mouseX, int mouseY);


int main(){
    RenderWindow window(VideoMode(800,600,32), "Test");
    window.setFramerateLimit(60);

    b2Vec2 gravity( 0.f, 9.8f);
    b2World world( gravity );
    createGround(world, 400.f, 500.f);


    Texture groundTexture;
    Texture boxTexture;

    groundTexture.loadFromFile("ground.png");
    boxTexture.loadFromFile("box.png");


    while( window.isOpen() ){
        window.clear( Color::White );

        for( b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext() ){
            if( bodyIterator->GetType() == b2_dynamicBody ){
                Sprite sprite;
                sprite.setTexture(boxTexture);
                sprite.setOrigin(16.f, 16.f);
                sprite.setPosition( SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
                sprite.setRotation( bodyIterator->GetAngle() * 180/b2_pi);
                window.draw(sprite);
            }
            else {
                Sprite groundSprite;
                groundSprite.setTexture( groundTexture );
                groundSprite.setOrigin( 400.f, 8.f );
                groundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);
                groundSprite.setRotation(180/b2_pi * bodyIterator->GetAngle());
                window.draw(groundSprite);
            }
        } 

        Event event;
        while( window.pollEvent(event) ){
            if( event.type == Event::Closed )
                window.close();
            if( Mouse::isButtonPressed( Mouse::Button::Left ) ){
                int MouseX = sf::Mouse::getPosition(window).x;
                int MouseY = sf::Mouse::getPosition(window).y;
                createBox(world, MouseX, MouseY);
            }

            world.Step( 1/60.f, 8, 3);
        }
    
        window.display();
    }
}

void createGround(b2World& world, float x, float y){
    b2BodyDef bodyDef;
    bodyDef.position = b2Vec2(x/30.f, y/30.f);
    bodyDef.type = b2_staticBody;
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox( (800.f/2)/SCALE, (16.f/2)/SCALE );
    b2FixtureDef fixtureDef;
    fixtureDef.density = 0.f;
    fixtureDef.shape = &shape;
    body->CreateFixture( &fixtureDef );
}

void createBox(b2World& world, int mouseX, int mouseY){
    b2BodyDef bodyDef;
    bodyDef.position = b2Vec2(mouseX/SCALE, mouseY/SCALE);
    bodyDef.type = b2_dynamicBody;
    b2Body* body = world.CreateBody(&bodyDef);
    
    b2PolygonShape shape;
    shape.SetAsBox( (32.f/2)/SCALE, (32.f/2)/SCALE );
    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.7f;
    fixtureDef.shape = &shape;
    body->CreateFixture( &fixtureDef);
}