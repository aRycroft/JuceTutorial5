/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class LimiterAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    LimiterAudioProcessorEditor (LimiterAudioProcessor&);
    ~LimiterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LimiterAudioProcessor& processor;
    Slider threshold, at, rt;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LimiterAudioProcessorEditor)
};
