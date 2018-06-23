/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
:   ticTacToe (3),
    gridSize (3),
    numOfGridSlots (3 * 3)
{
    createGrid();
    
    addAndMakeVisible (textLabel);
    textLabel.setText (translate ("Player 1: place your x..."), dontSendNotification);
    textLabel.setJustificationType (Justification::centred);
    
    addAndMakeVisible (gridSizeSlider);
    gridSizeSlider.setSliderStyle (Slider::LinearHorizontal);
    gridSizeSlider.setRange (3, 20, 1);
    gridSizeSlider.addListener (this);
    
    addAndMakeVisible (resetButton);
    resetButton.setButtonText (translate ("Reset"));
    resetButton.addListener (this);
    
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

//==============================================================================
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

//==============================================================================
void MainComponent::buttonClicked (Button *button)
{
    for (auto i = 0; i < gridButtons.size(); i++)
    {
        if (button == gridButtons[i])
        {
            std::cout << "Clicked grid button " << i << std::endl;
        }
    }
    
    if (button == &resetButton)
    {
        std::cout << "Clicked reset button" << std::endl;
    }
}

//==============================================================================
void MainComponent::sliderValueChanged (Slider *slider)
{
    if (slider == &gridSizeSlider)
    {
        gridSize = slider->getValue();
        numOfGridSlots = gridSize * gridSize;
        createGrid();
        resized();
        
        ticTacToe.setGridSize (gridSize);
    }
}

void MainComponent::createGrid()
{
    gridButtons.clear();
    
    for (auto i = 0; i < numOfGridSlots; i++)
    {
        gridButtons.insert (i, new TextButton());
        addAndMakeVisible (gridButtons[i]);
        gridButtons[i]->setClickingTogglesState (true);
        gridButtons[i]->addListener (this);
    }
}
