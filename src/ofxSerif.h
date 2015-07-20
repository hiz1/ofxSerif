//
//  ofxSerif.h
//  example
//
//  Created by hiz on 2015/07/04.
//
//

#ifndef __example__ofxSerif__
#define __example__ofxSerif__

#include <stdio.h>
#include <string>
#include "utf8helper.h"
#include "ofxEventAction.h"

extern const int OFXSERIF_UPDATE;
extern const int OFXSERIF_SPEEDUP;
extern const int OFXSERIF_SKIP;
extern const int OFXSERIF_NEXTPAGE;

class ofxSerif : public ofxEventAction {
public:
    void setText(const std::string text) {
        this->text         = text;
        this->textLength   = utf8_strlen(text);
        this->textFinished = false;
        this->textCursor   = 0;
    }
    std::string getText() {
        return utf8_substr(text, 0, textCursor);
    }
    bool isFinished() {
        return textFinished;
    }
protected:
    // 連続で同じイベントが起動された場合に初回のみ実行される処理
    virtual void startEvent(int type);
    // 連続で同じイベントが起動された場合に二回目以降に実行される処理
    virtual void loopEvent(int type) ;
    // 連続で同じイベントが起動された場合に最後に実行される処理
    // ※ 厳密にはイベントが最後に起動された次のフレームに実行される
    virtual void endEvent(int type);
private:
    std::string  text;
    unsigned int textLength;
    unsigned int textCursor;
    bool         textFinished;
};


#endif /* defined(__example__ofxSerif__) */
