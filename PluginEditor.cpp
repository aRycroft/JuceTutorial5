/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LimiterAudioProcessorEditor::LimiterAudioProcessorEditor (LimiterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    addAndMakeVisible(&threshold);
    threshold.setValue(0);
    threshold.setRange(-60.0f, 10.0f, 0.001);
    threshold.onValueChange = [this] {
        processor.limiterThresh = std::pow(10, (threshold.getValue() / 20));
    };

    addAndMakeVisible(&at);
    at.setRange(0.0f, 10.0f, 0.001);
    at.onValueChange = [this] {
        processor.attackTime = 1 - std::pow(MathConstants<float>::euler, ((1 / processor.getSampleRate()) * -2.2f) / at.getValue());
    };

    addAndMakeVisible(&rt);
    rt.setRange(0.0f, 10.0f, 0.001);
    rt.onValueChange = [this] {
        processor.releaseTime = 1 - std::pow(MathConstants<float>::euler, ((1 / processor.getSampleRate()) * -2.2f) / rt.getValue());
    };
}

LimiterAudioProcessorEditor::~LimiterAudioProcessorEditor()
{
}

//==============================================================================
void LimiterAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void LimiterAudioProcessorEditor::resized()
{
    threshold.setBounds(50, 50, 200, 50);
    at.setBounds(50, 150, 200, 50);
    rt.setBounds(50, 250, 200, 50);
   // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
