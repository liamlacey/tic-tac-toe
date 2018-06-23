/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../shared-code/TicTacToe.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public Button::Listener,
                        public Slider::Listener

{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void buttonClicked (Button *button) override;
    void sliderValueChanged (Slider *slider) override;

private:
    
    void createGrid();
    
    //==============================================================================
    // Your private member variables go here...
    
    OwnedArray<TextButton> gridButtons;
    Label textLabel;
    Slider gridSizeSlider;
    TextButton resetButton;
    
    TicTacToe ticTacToe;
    int gridSize, numOfGridSlots;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
