//
//  ofxSerif.cpp
//  example
//
//  Created by hiz on 2015/07/04.
//
//

#include "ofxSerif.h"

#include <iostream>

// 連続で同じイベントが起動された場合に初回のみ実行される処理
void ofxSerif::startEvent(int type) {
    switch (type) {
        case OFXSERIF_UPDATE:
            loopEvent(OFXSERIF_UPDATE);
            break;
        case OFXSERIF_SPEEDUP:
            loopEvent(OFXSERIF_UPDATE);
            break;
        case OFXSERIF_SKIP:
            textCursor = textLength;
            break;
        case OFXSERIF_NEXTPAGE:
            if(textCursor >= textLength) {
                textFinished = true;
            }
            break;
        default:
            break;
    }
}
// 連続で同じイベントが起動された場合に二回目以降に実行される処理
void ofxSerif::loopEvent(int type) {
    switch (type) {
        case OFXSERIF_UPDATE:
            if(textCursor < textLength) {
                textCursor ++;
                // 改行はスキップ
                if(textCursor < textLength && text.at(textCursor) == '\n') textCursor ++;
            }
            break;
        case OFXSERIF_SPEEDUP:
            loopEvent(OFXSERIF_UPDATE);
            break;
        default:
            break;
    }
}