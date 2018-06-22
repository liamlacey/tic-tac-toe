/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
:   ticTakToe (3),
    gridSize (3),
    numOfGridSlots (3 * 3)
{
    for (auto i = 0; i < numOfGridSlots; i++)
    {
        gridButtons.add (new TextButton());
        addAndMakeVisible (gridButtons[i]);
        
        gridButtons[i]->setClickingTogglesState (true);
    }
    
    addAndMakeVisible (textLabel);
    textLabel.setText (translate ("Player 1: place your x..."), dontSendNotification);
    textLabel.setJustificationType (Justification::centred);
    
    addAndMakeVisible (gridSizeSlider);
    gridSizeSlider.setSliderStyle (Slider::LinearHorizontal);
    gridSizeSlider.setRange(3, 20, 1);
    
    addAndMakeVisible (resetButton);
    resetButton.setButtonText (translate ("Reset"));
    
    setSize (600, 600);
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto gridWidth = getWidth() * 0.8;
    auto gridHeight = getHeight() * 0.8;
    auto gridX = getWidth() * 0.1;
    auto gridY = getHeight() * 0.1;
    auto gridButtonWidth = gridWidth / gridSize;
    auto gridButtonHeight = gridHeight / gridSize;
    
    for (auto row = 0; row < gridSize; row++)
    {
        for (auto col = 0; col < gridSize; col++)
        {
            gridButtons[(row * gridSize) + col]->setBounds (gridX + (gridButtonWidth * col),
                                                            gridY + (gridButtonHeight * row),
                                                            gridButtonWidth,
                                                            gridButtonHeight);
        }
    }
    
    textLabel.setBounds (0, 0, getWidth(), getHeight() * 0.1);
    
    gridSizeSlider.setBounds (0, getHeight() * 0.9, getWidth() / 2, getHeight() * 0.1);
    resetButton.setBounds (getWidth() / 2, getHeight() * 0.9, getWidth() / 2, getHeight() * 0.1);
    
}
