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
    textLabel.setText (translate ("Chose a new grid size (bottom slider), or PLAYER 1: Place Your X..."), dontSendNotification);
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
    
    resetButton.setBounds (getWidth() * 0.05, getHeight() * 0.91, (getWidth() / 2) * 0.8, getHeight() * 0.08);
    gridSizeSlider.setBounds ((getWidth() / 2) + (getWidth() * 0.05), getHeight() * 0.91, (getWidth() / 2) * 0.8, getHeight() * 0.08);
}

//==============================================================================
void MainComponent::buttonClicked (Button *button)
{
    for (auto i = 0; i < gridButtons.size(); i++)
    {
        if (button == gridButtons[i])
        {
            String buttonString("X");
            
            if (ticTacToe.getCurrentPlayer() == 1)
                buttonString = "O";
            
            button->setButtonText (buttonString);
            button->setEnabled(false);
            
            gridSizeSlider.setVisible (false);
            
            ticTacToe.setGridPositionStateForCurrentPlayer(i);
            checkGameStatus();
        }
    }
    
    if (button == &resetButton)
    {
        createGrid();
        gridSizeSlider.setVisible (true);
        textLabel.setText (translate ("Chose a new grid size (bottom slider), or PLAYER 1: Place Your X..."), dontSendNotification);
        
        ticTacToe.resetGame();
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
        
        ticTacToe.setGridSize (gridSize);
    }
}

//==============================================================================
void MainComponent::createGrid()
{
    gridButtons.clear();
    
    for (auto i = 0; i < numOfGridSlots; i++)
    {
        gridButtons.insert (i, new TextButton());
        addAndMakeVisible (gridButtons[i]);
        gridButtons[i]->setClickingTogglesState (true);
        gridButtons[i]->setEnabled (true);
        gridButtons[i]->addListener (this);
    }
    
    resized();
}

//==============================================================================
void MainComponent::disableGrid()
{
    for (auto i = 0; i < gridButtons.size(); i++)
        gridButtons[i]->setEnabled(false);
}

//==============================================================================
void MainComponent::checkGameStatus()
{
    int gameResult = ticTacToe.checkGameStatus();
    
    //If the game is still in play
    if (gameResult == TicTacToe::GAME_STATUS_CONTINUE)
    {
        ticTacToe.moveToNextPlayer();
        
        if (ticTacToe.getCurrentPlayer() == 0)
            textLabel.setText (translate ("PLAYER 1: Place Your X..."), dontSendNotification);
        else
            textLabel.setText (translate ("PLAYER 2: Place Your O..."), dontSendNotification);
    }
    else
    {
        //if there is now a winner
        if (gameResult == TicTacToe::GAME_STATUS_1_WON || gameResult == TicTacToe::GAME_STATUS_2_WON)
        {
            textLabel.setText (translate ("PLAYER ") + String (gameResult) + translate(" HAS WON! Press 'Reset' to play again."),
                              dontSendNotification);
            
            disableGrid();
        }
        //else all grid positions were used but no winner
        else
        {
            textLabel.setText (translate ("GAME OVER! Nobody won. Press 'Reset' to play again."),
                               dontSendNotification);
        }
    }
}


