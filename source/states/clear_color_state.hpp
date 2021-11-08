#pragma once

#include <application.hpp>

class ClearColorState: public our::State {
    // onInitialize() function is called once before the state starts
    void onInitialize() override {
        //TODO: Read the color from the configuration file and use it to set the clear color for the window
        //HINT: you can the configuration for the whole application using "getApp()->getConfig()"
        //To see how the clear color is written in the json files, see "config/blue-screen.json"
        //To know how read data from a nlohmann::json object, 
        //look at the following documentation: https://json.nlohmann.me/features/element_access/



        // Here we get the json of the scene configuration
        const auto& config = getApp()->getConfig()["scene"];

        // Here we get the json of the Clear color that has rbga info
        const auto& clearColor = config["clear-color"];

        // Here we extract the exact values of the color and alpha channels 
        GLfloat red =  clearColor["r"];
        GLfloat green = clearColor["g"];
        GLfloat blue = clearColor["b"];
        GLfloat alpha = clearColor["a"];

        // Here we set the default Clear color for our state 
        // we use the extracted values from the json config file as the values for the clear color
        glClearColor(red,green,blue,alpha);
        

    }

    // onDraw(deltaTime) function is called every frame 
    void onDraw(double deltaTime) override {
        //At the start of frame we want to clear the screen. Otherwise we would still see the results from the previous frame.
        glClear(GL_COLOR_BUFFER_BIT);
    }
};