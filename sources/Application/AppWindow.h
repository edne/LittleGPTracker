
#ifndef _APP_WINDOW_H_
#define _APP_WINDOW_H_

#include "UIFramework/SimpleBaseClasses/GUIWindow.h"
#include "Foundation/Observable.h"
#include "Application/Views/SongView.h"
#include "Application/Views/ChainView.h"
#include "Application/Views/PhraseView.h"
#include "Application/Views/ConsoleView.h"
#include "Application/Views/ProjectView.h"
#include "Application/Views/InstrumentView.h"
#include "Application/Views/TableView.h"
#include "Application/Views/NullView.h"
#include "Application/Views/MixerView.h"
#include "Application/Views/GrooveView.h"
#include "Application/Views/ViewData.h"
#include "System/io/Status.h"
#include "System/Process/SysMutex.h"

#define PROP_INVERT 0x80

class AppWindow:public GUIWindow,I_Observer,Status {
protected:
	AppWindow(I_GUIWindowImp &imp) ;
	virtual ~AppWindow() ;

public:
	static AppWindow *Create(GUICreateWindowParams &) ;
	void LoadProject(const Path &path) ;
	void CloseProject() ;

	virtual void Clear(bool all=false) ;
	virtual void ClearRect(GUIRect &rect) ;
	virtual void SetColor(ColorDefinition cd) ;
	void SetDirty() ;

protected: // GUIWindow implementation

	virtual bool onEvent(GUIEvent &event) ;
	virtual void onUpdate() ;
	virtual void LayoutChildren() ;
	virtual void Flush() ;
	virtual void Redraw() ;

	// override draw string to avoid going too far off
	// the screen.
	virtual void DrawString(const char *string,GUIPoint &pos,GUITextProperties &props,bool overlay=false);


      // I_Observer implementation

    virtual void Update(Observable &o,I_ObservableData *d) ;

	 // Status implementation

	virtual void Print(char *) ;

    void defineColor(const char *colorName,GUIColor &color) ;

	void onQuitApp() ;
private:

	View *_currentView ;
	ViewData *_viewData ;
	SongView *_songView ;
	ChainView *_chainView ;
	PhraseView *_phraseView ;
	ProjectView *_projectView ;
	InstrumentView *_instrumentView ;
	TableView *_tableView ;
	GrooveView *_grooveView ;
	NullView *_nullView ;
	MixerView *_mixerView ;

	Path _root ;

	bool _isDirty ;
	bool _closeProject ;
	bool _loadAfterSaveAsProject ;
	bool _shouldQuit ;
	unsigned short _mask ;
	unsigned long _lastA ;
	unsigned long _lastB ;
	char _statusLine[80] ;
	char _newProjectToLoad[80];
	unsigned char _charScreen[1200] ;
	unsigned char _charScreenProp[1200] ;
	unsigned char _preScreen[1200] ;
	unsigned char _preScreenProp[1200] ;

    static GUIColor backgroundColor_ ;
    static GUIColor normalColor_ ;
    static GUIColor highlight2Color_;
    static GUIColor highlightColor_;
    static GUIColor consoleColor_;
    static GUIColor cursorColor_;
    static GUIColor zeroColor_;

    static GUIColor rownumberColor_;
    static GUIColor rownumber2Color_;

	ColorDefinition colorIndex_ ;

	static int charWidth_ ;
	static int charHeight_ ;
	
	SysMutex drawMutex_ ;
} ;



#endif

