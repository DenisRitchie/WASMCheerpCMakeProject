#ifndef __CHEERPS_VANILLAJS_EVENTS_HPP__
#define __CHEERPS_VANILLAJS_EVENTS_HPP__

#include <cheerp/client.h>
#include <cheerp/clientlib.h>

#define DECLARE_EVENT_CONSTANT(event_name) __DECLARE_EVENT_CONSTANT(event_name, event_name)
#define __DECLARE_EVENT_CONSTANT(event_name, event_constant_value) \
  inline constexpr const wchar_t event_name[] = L ## #event_constant_value;

/// 
/// References:
///   https://developer.mozilla.org/en-US/docs/Web/Events
///   https://developer.mozilla.org/en-US/docs/Web/API/Document#Events
/// 

namespace [[cheerp::genericjs]] VanillaJS
{
  namespace [[cheerp::genericjs]] Events
  {
    namespace [[cheerp::genericjs]] Resource
    {
      // A resource failed to load.
      DECLARE_EVENT_CONSTANT(error)

      // The loading of a resource has been aborted.
      DECLARE_EVENT_CONSTANT(abort)

      // A resource and its dependent resources have finished loading.
      DECLARE_EVENT_CONSTANT(load)

      // The window, the document and its resources are about to be unloaded.
      DECLARE_EVENT_CONSTANT(beforeunload)

      // The document or a dependent resource is being unloaded.
      DECLARE_EVENT_CONSTANT(unload)
    } // namespace Resource

    namespace [[cheerp::genericjs]] Network
    {
      // The browser has gained access to the network.
      DECLARE_EVENT_CONSTANT(online)

      // The browser has lost access to the network.
      DECLARE_EVENT_CONSTANT(offline)
    } // namespace Network

    namespace [[cheerp::genericjs]] Focus
    {
      // An element has received focus (does not bubble).
      DECLARE_EVENT_CONSTANT(focus)

      // An element has lost focus (does not bubble).
      DECLARE_EVENT_CONSTANT(blur)

      // An element is about to receive focus (does bubble).
      DECLARE_EVENT_CONSTANT(focusin)

      // An element is about to lose focus (does bubble).
      DECLARE_EVENT_CONSTANT(focusout)
    } // namespace Focus

    namespace [[cheerp::genericjs]] WebSocket
    {
      // A WebSocket connection has been established.
      DECLARE_EVENT_CONSTANT(open)

      // A message is received through a WebSocket.
      DECLARE_EVENT_CONSTANT(message)

      // A WebSocket connection has been closed with prejudice (some data couldn't be sent for example).
      DECLARE_EVENT_CONSTANT(error)

      // A WebSocket connection has been closed.
      DECLARE_EVENT_CONSTANT(close)
    } // namespace WebSocket

    namespace [[cheerp::genericjs]] SessionHistory
    {
      // A session history entry is being traversed from.
      DECLARE_EVENT_CONSTANT(pagehide)

      // A session history entry is being traversed to.
      DECLARE_EVENT_CONSTANT(pageshow)

      // A session history entry is being navigated to (in certain cases).
      DECLARE_EVENT_CONSTANT(popstate)
    } // namespace SessionHistory 

    namespace [[cheerp::genericjs]] CSSAnimation
    {
      // A CSS animation has started.
      DECLARE_EVENT_CONSTANT(animationstart)

      // A CSS animation has aborted.
      DECLARE_EVENT_CONSTANT(animationcancel)

      // A CSS animation has completed.
      DECLARE_EVENT_CONSTANT(animationend)

      // A CSS animation is repeated.
      DECLARE_EVENT_CONSTANT(animationiteration)
    } // namespace CSSAnimation

    namespace [[cheerp::genericjs]] CSSTransition
    {
      // A CSS transition has actually started (fired after any delay).
      DECLARE_EVENT_CONSTANT(transitionstart)

      // A CSS transition has been cancelled.
      DECLARE_EVENT_CONSTANT(transitioncancel)

      // A CSS transition has completed.
      DECLARE_EVENT_CONSTANT(transitionend)

      // A CSS transition has begun running (fired before any delay starts).
      DECLARE_EVENT_CONSTANT(transitionrun)
    } // namespace CSSTransition

    namespace [[cheerp::genericjs]] Form
    {
      // The reset button is pressed.
      DECLARE_EVENT_CONSTANT(reset)

      // The submit button is pressed.
      DECLARE_EVENT_CONSTANT(submit)
    } // namespace Form

    namespace [[cheerp::genericjs]] Printing
    {
      // The print dialog is opened.
      DECLARE_EVENT_CONSTANT(beforeprint)

      // The print dialog is closed.
      DECLARE_EVENT_CONSTANT(afterprint)
    } // namespace Printing

    namespace [[cheerp::genericjs]] TextComposition
    {
      // The composition of a passage of text is prepared (similar to keydown for a keyboard input, 
      // but works with other inputs such as speech recognition).
      DECLARE_EVENT_CONSTANT(compositionstart)

      // A character is added to a passage of text being composed.
      DECLARE_EVENT_CONSTANT(compositionupdate)

      // The composition of a passage of text has been completed or canceled.
      DECLARE_EVENT_CONSTANT(compositionend)
    } // namespace TextComposition

    namespace [[cheerp::genericjs]] View
    {
      // An element was toggled to or from fullscreen mode.
      DECLARE_EVENT_CONSTANT(fullscreenchange)

      // It was impossible to switch to fullscreen mode for technical reasons or because the permission was denied.
      DECLARE_EVENT_CONSTANT(fullscreenerror)

      // The document view has been resized.
      DECLARE_EVENT_CONSTANT(resize)

      // The document view or an element has been scrolled.
      DECLARE_EVENT_CONSTANT(scroll)
    } // namespace View

    namespace [[cheerp::genericjs]] Clipboard
    {
      // The selection has been cut and copied to the clipboard.
      DECLARE_EVENT_CONSTANT(cut)

      // The selection has been copied to the clipboard.
      DECLARE_EVENT_CONSTANT(copy)

      // The item from the clipboard has been pasted.
      DECLARE_EVENT_CONSTANT(paste)
    } // namespace Clipboard

    namespace [[cheerp::genericjs]] Keyboard
    {
      // ANY key is pressed.
      DECLARE_EVENT_CONSTANT(keydown)

      // ANY key (except Shift, Fn, or CapsLock) is in a pressed position (fired continuously).
      DECLARE_EVENT_CONSTANT(keypress)

      // ANY key is released.
      DECLARE_EVENT_CONSTANT(keyup)
    } // namespace Keyboard

    namespace [[cheerp::genericjs]] Mouse
    {
      // A pointing device button (ANY non-primary button) has been pressed and released on an element.
      DECLARE_EVENT_CONSTANT(auxclick)

      // A pointing device button (ANY button; soon to be primary button only) has been pressed and released on an element.
      DECLARE_EVENT_CONSTANT(click)

      // The right button of the mouse is clicked (before the context menu is displayed).
      DECLARE_EVENT_CONSTANT(contextmenu)

      // A pointing device button is clicked twice on an element.
      DECLARE_EVENT_CONSTANT(dblclick)

      // A pointing device button is pressed on an element.
      DECLARE_EVENT_CONSTANT(mousedown)

      // A pointing device is moved onto the element that has the listener attached.
      DECLARE_EVENT_CONSTANT(mouseenter)

      // A pointing device is moved off the element that has the listener attached.
      DECLARE_EVENT_CONSTANT(mouseleave)

      // A pointing device is moved over an element (fired continuously as the mouse moves).
      DECLARE_EVENT_CONSTANT(mousemove)

      // A pointing device is moved onto the element that has the listener attached or onto one of its children.
      DECLARE_EVENT_CONSTANT(mouseover)

      // A pointing device is moved off the element that has the listener attached or off one of its children.
      DECLARE_EVENT_CONSTANT(mouseout)

      // A pointing device button is released over an element.
      DECLARE_EVENT_CONSTANT(mouseup)

      // The pointer was locked or released.
      DECLARE_EVENT_CONSTANT(pointerlockchange)

      // It was impossible to lock the pointer for technical reasons or because the permission was denied.
      DECLARE_EVENT_CONSTANT(pointerlockerror)

      // Some text is being selected.
      DECLARE_EVENT_CONSTANT(select)

      // A wheel button of a pointing device is rotated in any direction.
      DECLARE_EVENT_CONSTANT(wheel)
    } // namespace Mouse

    namespace [[cheerp::genericjs]] DragAndDrop
    {
      // An element or text selection is being dragged (fired continuously every 350ms).
      DECLARE_EVENT_CONSTANT(drag)

      // A drag operation is being ended (by releasing a mouse button or hitting the escape key).
      DECLARE_EVENT_CONSTANT(dragend)

      // A dragged element or text selection enters a valid drop target.
      DECLARE_EVENT_CONSTANT(dragenter)

      // The user starts dragging an element or text selection.
      DECLARE_EVENT_CONSTANT(dragstart)

      // A dragged element or text selection leaves a valid drop target.
      DECLARE_EVENT_CONSTANT(dragleave)

      // An element or text selection is being dragged over a valid drop target (fired continuously every 350ms).
      DECLARE_EVENT_CONSTANT(dragover)

      // An element is dropped on a valid drop target.
      DECLARE_EVENT_CONSTANT(drop)
    } // namespace DragAndDrop

    namespace [[cheerp::genericjs]] Media
    {
      // The input buffer of a ScriptProcessorNode is ready to be processed.
      DECLARE_EVENT_CONSTANT(audioprocess)

      // The browser can play the media, but estimates that not enough data has
      // been loaded to play the media up to its end without having to stop for further buffering of content.
      DECLARE_EVENT_CONSTANT(canplay)

      // The browser estimates it can play the media up to its end without stopping for content buffering.
      DECLARE_EVENT_CONSTANT(canplaythrough)

      // The rendering of an OfflineAudioContext is terminated.
      DECLARE_EVENT_CONSTANT(complete)

      // The duration attribute has been updated.
      DECLARE_EVENT_CONSTANT(durationchange)

      // The media has become empty; for example, this event is sent if the media has already been
      // loaded (or partially loaded), and the load() method is called to reload it.
      DECLARE_EVENT_CONSTANT(emptied)

      // 	Playback has stopped because the end of the media was reached.
      DECLARE_EVENT_CONSTANT(ended)

      // The first frame of the media has finished loading.
      DECLARE_EVENT_CONSTANT(loadeddata)

      // The metadata has been loaded.
      DECLARE_EVENT_CONSTANT(loadedmetadata)

      // Playback has been paused.
      DECLARE_EVENT_CONSTANT(pause)

      // Playback has begun.
      DECLARE_EVENT_CONSTANT(play)

      // Playback is ready to start after having been paused or delayed due to lack of data.
      DECLARE_EVENT_CONSTANT(playing)

      // The playback rate has changed.
      DECLARE_EVENT_CONSTANT(ratechange)

      // A seek operation completed.
      DECLARE_EVENT_CONSTANT(seeked)

      // A seek operation began.
      DECLARE_EVENT_CONSTANT(seeking)

      // The user agent is trying to fetch media data, but data is unexpectedly not forthcoming.
      DECLARE_EVENT_CONSTANT(stalled)

      // 	Media data loading has been suspended.
      DECLARE_EVENT_CONSTANT(suspend)

      // The time indicated by the currentTime attribute has been updated.
      DECLARE_EVENT_CONSTANT(timeupdate)

      // 	The volume has changed.
      DECLARE_EVENT_CONSTANT(volumechange)

      // Playback has stopped because of a temporary lack of data.
      DECLARE_EVENT_CONSTANT(waiting)
    } // namespace Media

    namespace [[cheerp::genericjs]] Progress
    {
      // Progression has been terminated (not due to an error).
      DECLARE_EVENT_CONSTANT(abort)

      // Progression has failed.
      DECLARE_EVENT_CONSTANT(error)

      // Progression has been successful.
      DECLARE_EVENT_CONSTANT(load)

      // Progress has stopped (after "error", "abort", or "load" have been dispatched).
      DECLARE_EVENT_CONSTANT(loadend)

      // Progress has begun.
      DECLARE_EVENT_CONSTANT(loadstart)

      // In progress.
      DECLARE_EVENT_CONSTANT(progress)

      // Progression is terminated due to preset time expiring.
      DECLARE_EVENT_CONSTANT(timeout)
    } // namespace Progress

    namespace [[cheerp::genericjs]] Storage
    {
      DECLARE_EVENT_CONSTANT(change)
      DECLARE_EVENT_CONSTANT(storage)
    } // namespace Storage

    namespace [[cheerp::genericjs]] Update
    {
      DECLARE_EVENT_CONSTANT(checking)
      DECLARE_EVENT_CONSTANT(downloading)
      DECLARE_EVENT_CONSTANT(error)
      DECLARE_EVENT_CONSTANT(noupdate)
      DECLARE_EVENT_CONSTANT(obsolete)
      DECLARE_EVENT_CONSTANT(updateready)
    } // namespace Update

    namespace [[cheerp::genericjs]] Value_Change
    {
      DECLARE_EVENT_CONSTANT(broadcast)
      DECLARE_EVENT_CONSTANT(CheckboxStateChange)
      DECLARE_EVENT_CONSTANT(hashchange)
      DECLARE_EVENT_CONSTANT(input)
      DECLARE_EVENT_CONSTANT(RadioStateChange)
      DECLARE_EVENT_CONSTANT(readystatechange)
      DECLARE_EVENT_CONSTANT(ValueChange)
    } // namespace ValueChange

    namespace [[cheerp::genericjs]] Uncategorized
    {
      DECLARE_EVENT_CONSTANT(invalid)
      DECLARE_EVENT_CONSTANT(message)
      DECLARE_EVENT_CONSTANT(open)
      DECLARE_EVENT_CONSTANT(show)
    } // namespace Uncategorized

    namespace [[cheerp::genericjs]] AbortableFetch
    {
      // A DOM request is aborted, i.e. using AbortController.abort().
      DECLARE_EVENT_CONSTANT(abort)
    } // namespace AbortableFetch

    namespace [[cheerp::genericjs]] WebVR
    {
      // When a VR display is able to be presented to, 
      // for example if an HMD has been moved to bring it out of standby, or woken up by being put on.
      DECLARE_EVENT_CONSTANT(vrdisplayactivate)

      // when presentation to a VRDisplay has been paused for some reason by the browser, OS, or VR hardware — 
      // for example, while the user is interacting with a system menu or browser, 
      // to prevent tracking or loss of experience.
      DECLARE_EVENT_CONSTANT(vrdisplayblur)

      // when a compatible VRDisplay is connected to the computer.
      DECLARE_EVENT_CONSTANT(vrdisplayconnect)

      // When a VRDisplay can no longer be presented to,
      // for example if an HMD has gone into standby or sleep mode due to a period of inactivity.
      DECLARE_EVENT_CONSTANT(vrdisplaydeactivate)

      // When a compatible VRDisplay is disconnected from the computer.
      DECLARE_EVENT_CONSTANT(vrdisplaydisconnect)

      // When presentation to a VRDisplay has resumed after being blurred.
      DECLARE_EVENT_CONSTANT(vrdisplayfocus)

      // The presenting state of a VRDisplay changes — i.e. goes from presenting to not presenting, or vice versa.
      DECLARE_EVENT_CONSTANT(vrdisplaypresentchange)
    } // namespace WebVR

    namespace [[cheerp::genericjs]] SVG
    {
      DECLARE_EVENT_CONSTANT(SVGAbort)
      DECLARE_EVENT_CONSTANT(SVGError)
      DECLARE_EVENT_CONSTANT(SVGLoad)
      DECLARE_EVENT_CONSTANT(SVGResize)
      DECLARE_EVENT_CONSTANT(SVGScroll)
      DECLARE_EVENT_CONSTANT(SVGUnload)
      DECLARE_EVENT_CONSTANT(SVGZoom)
    } // namespace SVG

    namespace [[cheerp::genericjs]] Database
    {
      DECLARE_EVENT_CONSTANT(abort)
      DECLARE_EVENT_CONSTANT(blocked)
      DECLARE_EVENT_CONSTANT(complete)
      DECLARE_EVENT_CONSTANT(error)
      DECLARE_EVENT_CONSTANT(success)
      DECLARE_EVENT_CONSTANT(upgradeneeded)
      DECLARE_EVENT_CONSTANT(versionchange)
    } // namespace Database

    namespace [[cheerp::genericjs]] Script
    {
      DECLARE_EVENT_CONSTANT(afterscriptexecute)
      DECLARE_EVENT_CONSTANT(beforescriptexecute)
    } // namespace Script

    namespace [[cheerp::genericjs]] Menu
    {
      DECLARE_EVENT_CONSTANT(DOMMenuItemActive)
      DECLARE_EVENT_CONSTANT(DOMMenuItemInactive)
    } // namespace Menu

    namespace [[cheerp::genericjs]] Window
    {
      DECLARE_EVENT_CONSTANT(close)
    } // namespace Window

    namespace [[cheerp::genericjs]] Popup
    {
      DECLARE_EVENT_CONSTANT(popuphidden)
      DECLARE_EVENT_CONSTANT(popuphiding)
      DECLARE_EVENT_CONSTANT(popupshowing)
      DECLARE_EVENT_CONSTANT(popupshown)
    } // namespace Popup

    namespace [[cheerp::genericjs]] Tab
    {
      DECLARE_EVENT_CONSTANT(visibilitychange)
    } // namespace Tab

    namespace [[cheerp::genericjs]] Battery
    {
      DECLARE_EVENT_CONSTANT(chargingchange)
      DECLARE_EVENT_CONSTANT(chargingtimechange)
      DECLARE_EVENT_CONSTANT(dischargingtimechange)
      DECLARE_EVENT_CONSTANT(levelchange)
    } // namespace Battery

    namespace [[cheerp::genericjs]] Call
    {
      DECLARE_EVENT_CONSTANT(alerting)
      DECLARE_EVENT_CONSTANT(busy)
      DECLARE_EVENT_CONSTANT(callschanged)
      DECLARE_EVENT_CONSTANT(cfstatechange)
      DECLARE_EVENT_CONSTANT(connected)
      DECLARE_EVENT_CONSTANT(connecting)
      DECLARE_EVENT_CONSTANT(dialing)
      DECLARE_EVENT_CONSTANT(disconnected)
      DECLARE_EVENT_CONSTANT(disconnecting)
      DECLARE_EVENT_CONSTANT(error)
      DECLARE_EVENT_CONSTANT(held)
      DECLARE_EVENT_CONSTANT(holding)
      DECLARE_EVENT_CONSTANT(incoming)
      DECLARE_EVENT_CONSTANT(resuming)
      DECLARE_EVENT_CONSTANT(statechange)
      DECLARE_EVENT_CONSTANT(voicechange)
    } // namespace Call

    namespace [[cheerp::genericjs]] Sensor
    {
      DECLARE_EVENT_CONSTANT(compassneedscalibration)
      DECLARE_EVENT_CONSTANT(devicemotion)
      DECLARE_EVENT_CONSTANT(deviceorientation)
      DECLARE_EVENT_CONSTANT(orientationchange)
    } // namespace Sensor

    namespace [[cheerp::genericjs]] Smartcard
    {
      DECLARE_EVENT_CONSTANT(icccardlockerror)
      DECLARE_EVENT_CONSTANT(iccinfochange)
      __DECLARE_EVENT_CONSTANT(smartcard_insert, smartcard-insert)
      __DECLARE_EVENT_CONSTANT(smartcard_remove, smartcard-remove)
      DECLARE_EVENT_CONSTANT(stkcommand)
      DECLARE_EVENT_CONSTANT(stksessionend)
      DECLARE_EVENT_CONSTANT(cardstatechange)
    } // namespace Smartcard

    namespace [[cheerp::genericjs]] SMSAndUSSD
    {
      DECLARE_EVENT_CONSTANT(delivered)
      DECLARE_EVENT_CONSTANT(received)
      DECLARE_EVENT_CONSTANT(sent)
      DECLARE_EVENT_CONSTANT(ussdreceived)
    } // namespace SMSAndUSSD

    namespace [[cheerp::genericjs]] Frame
    {
      DECLARE_EVENT_CONSTANT(mozbrowserclose)
      DECLARE_EVENT_CONSTANT(mozbrowsercontextmenu)
      DECLARE_EVENT_CONSTANT(mozbrowsererror)
      DECLARE_EVENT_CONSTANT(mozbrowsericonchange)
      DECLARE_EVENT_CONSTANT(mozbrowserlocationchange)
      DECLARE_EVENT_CONSTANT(mozbrowserloadend)
      DECLARE_EVENT_CONSTANT(mozbrowserloadstart)
      DECLARE_EVENT_CONSTANT(mozbrowseropenwindow)
      DECLARE_EVENT_CONSTANT(mozbrowsersecuritychange)
      DECLARE_EVENT_CONSTANT(mozbrowsershowmodalprompt)
      DECLARE_EVENT_CONSTANT(mozbrowsertitlechange)
    } // namespace Frame

    namespace [[cheerp::genericjs]] DOMMutation
    {
      DECLARE_EVENT_CONSTANT(DOMAttributeNameChanged)
      DECLARE_EVENT_CONSTANT(DOMAttrModified)
      DECLARE_EVENT_CONSTANT(DOMCharacterDataModified)
      DECLARE_EVENT_CONSTANT(DOMContentLoaded)
      DECLARE_EVENT_CONSTANT(DOMElementNameChanged)
      DECLARE_EVENT_CONSTANT(DOMNodeInserted)
      DECLARE_EVENT_CONSTANT(DOMNodeInsertedIntoDocument)
      DECLARE_EVENT_CONSTANT(DOMNodeRemoved)
      DECLARE_EVENT_CONSTANT(DOMNodeRemovedFromDocument)
      DECLARE_EVENT_CONSTANT(DOMSubtreeModified)
    } // namespace DOMMutation

    namespace [[cheerp::genericjs]] Touch
    {
      DECLARE_EVENT_CONSTANT(touchcancel)
      DECLARE_EVENT_CONSTANT(touchend)
      DECLARE_EVENT_CONSTANT(touchmove)
      DECLARE_EVENT_CONSTANT(touchstart)
    } // namespace Touch

    namespace [[cheerp::genericjs]] Pointer
    {
      DECLARE_EVENT_CONSTANT(pointerover)
      DECLARE_EVENT_CONSTANT(pointerenter)
      DECLARE_EVENT_CONSTANT(pointerdown)
      DECLARE_EVENT_CONSTANT(pointermove)
      DECLARE_EVENT_CONSTANT(pointerup)
      DECLARE_EVENT_CONSTANT(pointercancel)
      DECLARE_EVENT_CONSTANT(pointerout)
      DECLARE_EVENT_CONSTANT(pointerleave)
      DECLARE_EVENT_CONSTANT(gotpointercapture)
      DECLARE_EVENT_CONSTANT(lostpointercapture)
      DECLARE_EVENT_CONSTANT(pointerlockchange)
      DECLARE_EVENT_CONSTANT(pointerlockerror)
    } // namespace Pointer

    namespace [[cheerp::genericjs]] Standard
    {
      // The loading of a resource has been aborted.
      __DECLARE_EVENT_CONSTANT(UIEventAbort, abort)

      // Progression has been terminated (not due to an error).
      __DECLARE_EVENT_CONSTANT(ProgressEventAbort, abort)

      // A transaction has been aborted.
      __DECLARE_EVENT_CONSTANT(EventAbort, abort)

      // The associated document has started printing or the print preview has been closed.
      DECLARE_EVENT_CONSTANT(afterprint)

      // A CSS animation has aborted.
      DECLARE_EVENT_CONSTANT(animationcancel)

      // A CSS animation has completed.
      DECLARE_EVENT_CONSTANT(animationend)

      // A CSS animation is repeated.
      DECLARE_EVENT_CONSTANT(animationiteration)

      // A CSS animation has started.
      DECLARE_EVENT_CONSTANT(animationstart)

      // A web application is successfully installed as a progressive web app.
      DECLARE_EVENT_CONSTANT(appinstalled)

      // The input buffer of a ScriptProcessorNode is ready to be processed.
      DECLARE_EVENT_CONSTANT(audioprocess)

      // The user agent has finished capturing audio for speech recognition.
      DECLARE_EVENT_CONSTANT(audioend)

      // The user agent has started to capture audio for speech recognition.
      DECLARE_EVENT_CONSTANT(audiostart)

      // The associated document is about to be printed or previewed for printing.
      DECLARE_EVENT_CONSTANT(beforeprint)

      // The window, the document and its resources are about to be unloaded.
      DECLARE_EVENT_CONSTANT(beforeunload)

      // A SMIL animation element begins. https://developer.mozilla.org/en-US/docs/Web/SVG/SVG_animation_with_SMIL
      __DECLARE_EVENT_CONSTANT(BeginEvent, beginEvent)

      // An open connection to a database is blocking a versionchange transaction on the same database.
      DECLARE_EVENT_CONSTANT(blocked)

      // An element has lost focus (does not bubble).
      DECLARE_EVENT_CONSTANT(blur)

      // The spoken utterance reaches a word or sentence boundary
      DECLARE_EVENT_CONSTANT(boundary)

      // The user agent can play the media, but estimates that not enough data has been loaded to play 
      // the media up to its end without having to stop for further buffering of content.
      DECLARE_EVENT_CONSTANT(canplay)

      // The user agent can play the media up to its end without having to stop for further buffering of content.
      DECLARE_EVENT_CONSTANT(canplaythrough)

      // The change event is fired for <input>, <select>, and <textarea> elements 
      // when a change to the element's value is committed by the user.
      DECLARE_EVENT_CONSTANT(change)

      // The battery begins or stops charging.
      DECLARE_EVENT_CONSTANT(chargingchange)

      // The chargingTime attribute has been updated.
      DECLARE_EVENT_CONSTANT(chargingtimechange)

      // A pointing device button has been pressed and released on an element.
      DECLARE_EVENT_CONSTANT(click)

      // A WebSocket connection has been closed.
      DECLARE_EVENT_CONSTANT(close)

      // A transaction successfully completed.
      __DECLARE_EVENT_CONSTANT(IndexedDBComplete, complete)

      // The rendering of an OfflineAudioContext is terminated.
      __DECLARE_EVENT_CONSTANT(OfflineAudioCompletionEventComplete, complete)

      // The composition of a passage of text has been completed or canceled.
      DECLARE_EVENT_CONSTANT(compositionend)

      // The composition of a passage of text is prepared
      // (similar to keydown for a keyboard input, but works with other inputs such as speech recognition).
      DECLARE_EVENT_CONSTANT(compositionstart)

      // A character is added to a passage of text being composed.
      DECLARE_EVENT_CONSTANT(compositionupdate)

      // The right button of the mouse is clicked (before the context menu is displayed).
      DECLARE_EVENT_CONSTANT(contextmenu)

      // The text selection has been added to the clipboard.
      DECLARE_EVENT_CONSTANT(copy)

      // The text selection has been removed from the document and added to the clipboard.
      DECLARE_EVENT_CONSTANT(cut)

      // A pointing device button is clicked twice on an element.
      DECLARE_EVENT_CONSTANT(dblclick)

      // A media device such as a camera, microphone, or speaker is connected or removed from the system.
      DECLARE_EVENT_CONSTANT(devicechange)

      // Fresh data is available from a motion sensor.
      DECLARE_EVENT_CONSTANT(devicemotion)

      // Fresh data is available from an orientation sensor.
      DECLARE_EVENT_CONSTANT(deviceorientation)

      // The dischargingTime attribute has been updated.
      DECLARE_EVENT_CONSTANT(dischargingtimechange)

      // A button, link, or state changing element is activated (use click instead).
      DECLARE_EVENT_CONSTANT(DOMActivate)

      // The name of an attribute changed (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMAttributeNameChanged)

      // The value of an attribute has been modified (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMAttrModified)

      // A text or another CharacterData has changed (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMCharacterDataModified)

      // The document has finished loading (but not its dependent resources).
      DECLARE_EVENT_CONSTANT(DOMContentLoaded)

      // The name of an element changed (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMElementNameChanged)

      // An element has received focus (use focus or focusin instead).
      DECLARE_EVENT_CONSTANT(DOMFocusIn)

      // 	An element has lost focus (use blur or focusout instead).
      DECLARE_EVENT_CONSTANT(DOMFocusOut)

      // A node has been added as a child of another node (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMNodeInserted)

      // A node has been inserted into the document (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMNodeInsertedIntoDocument)

      // A node has been removed from its parent node (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMNodeRemoved)

      // A node has been removed from the document (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMNodeRemovedFromDocument)

      // A change happened in the document (use mutation observers instead).
      DECLARE_EVENT_CONSTANT(DOMSubtreeModified)

      // An element or text selection is being dragged (every 350ms).
      DECLARE_EVENT_CONSTANT(drag)

      // A drag operation is being ended (by releasing a mouse button or hitting the escape key).
      DECLARE_EVENT_CONSTANT(dragend)

      // A dragged element or text selection enters a valid drop target.
      DECLARE_EVENT_CONSTANT(dragenter)

      // A dragged element or text selection leaves a valid drop target.
      DECLARE_EVENT_CONSTANT(dragleave)

      // An element or text selection is being dragged over a valid drop target (fires every 350ms).
      DECLARE_EVENT_CONSTANT(dragover)

      // The user starts dragging an element or text selection.
      DECLARE_EVENT_CONSTANT(dragstart)

      // An element is dropped on a valid drop target.
      DECLARE_EVENT_CONSTANT(drop)

      // The duration attribute has been updated.
      DECLARE_EVENT_CONSTANT(durationchange)

      // The media has become empty. For example, this event is triggered if the media has already 
      // been loaded (or partially loaded), and the load() method is called to reload it.
      DECLARE_EVENT_CONSTANT(emptied)

      // The speech recognition service has disconnected.
      // The utterance has finished being spoken.
      DECLARE_EVENT_CONSTANT(end)

      // Playback has stopped because the end of the media was reached.
      DECLARE_EVENT_CONSTANT(ended)

      // A SMIL animation element ends.
      __DECLARE_EVENT_CONSTANT(EndEvent, endEvent)

      // A resource failed to load.
      __DECLARE_EVENT_CONSTANT(UIEventError, error)

      // 	Progression has failed.
      __DECLARE_EVENT_CONSTANT(ProgressEventError, error)

      // A WebSocket connection has been closed with prejudice (some data couldn't be sent for example).
      __DECLARE_EVENT_CONSTANT(ServerSentEventError, error)

      // An event source connection has been failed.
      __DECLARE_EVENT_CONSTANT(IndexedDBEventError, error)

      // A request caused an error and failed.
      __DECLARE_EVENT_CONSTANT(WebSpeechAPIEventError, error)

      // A speech recognition error occurs.
      __DECLARE_EVENT_CONSTANT(SpeechRecognitionEventError, error)

      // An element has received focus (does not bubble).
      DECLARE_EVENT_CONSTANT(focus)

      // An element is about to receive focus (bubbles).
      DECLARE_EVENT_CONSTANT(focusin)

      // An element is about to lose focus (bubbles).
      DECLARE_EVENT_CONSTANT(focusout)

      // An element was toggled to or from fullscreen mode.
      DECLARE_EVENT_CONSTANT(fullscreenchange)

      // It was impossible to switch to fullscreen mode for technical reasons or because the permission was denied.
      DECLARE_EVENT_CONSTANT(fullscreenerror)

      // A gamepad has been connected.
      DECLARE_EVENT_CONSTANT(gamepadconnected)

      // A gamepad has been disconnected.
      DECLARE_EVENT_CONSTANT(gamepaddisconnected)

      // Element receives pointer capture.
      DECLARE_EVENT_CONSTANT(gotpointercapture)

      // The fragment identifier of the URL has changed (the part of the URL after the #).
      DECLARE_EVENT_CONSTANT(hashchange)

      // Element lost pointer capture.
      DECLARE_EVENT_CONSTANT(lostpointercapture)

      // The value of an element changes or the content of an element with the attribute contenteditable is modified.
      DECLARE_EVENT_CONSTANT(input)

      // A submittable element has been checked and doesn't satisfy its constraints.
      DECLARE_EVENT_CONSTANT(invalid)

      // A key is pressed down.
      DECLARE_EVENT_CONSTANT(keydown)

      // A key is pressed down, and that key normally produces a character value (use input event instead).
      DECLARE_EVENT_CONSTANT(keypress)

      // 	A key is released.
      DECLARE_EVENT_CONSTANT(keyup)

      // The user's preferred languages have changed.
      DECLARE_EVENT_CONSTANT(languagechange)

      // The level attribute has been updated.
      DECLARE_EVENT_CONSTANT(levelchange)

      // TODO: Complete the event list
    } // namespace Standard
  } // namespace Events
} // namespace VanillaJS

#undef DECLARE_EVENT_CONSTANT
#undef __DECLARE_EVENT_CONSTANT

#endif // !__CHEERPS_VANILLAJS_EVENTS_HPP__