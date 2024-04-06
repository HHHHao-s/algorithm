
#include "s.h"
/*
 * @lc app=leetcode.cn id=2296 lang=cpp
 *
 * [2296] 设计一个文本编辑器
 */

// @lc code=start
class TextEditor {
private:
    string left, right;

public:
    TextEditor() {
        left.reserve(1000000);
        right.reserve(1000000);
    }
    
    void addText(string text) {

        left += text;

    }
    
    int deleteText(int k) {

        int dl = min(k,(int) left.size());


        left = left.substr(0, left.size()-dl);

        return dl;

    }
    
    string cursorLeft(int k) {

        for(int i=0;i<k;i++){
            if(left.empty()){
                break;
            }
            right.push_back(left.back());
            left.pop_back();
            if(left.empty()){
                break;
            }
        }

        if(left.size()>10){
            return left.substr(left.size()-10, 10);
        }
        return left;
    }
    
    string cursorRight(int k) {

        for(int i=0;i<k;i++){
            if(right.empty()){
                break;
            }
            left.push_back(right.back());
            right.pop_back();
            
        }
        if(left.size()>10){
            return left.substr(left.size()-10, 10);
        }
        return left;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end

