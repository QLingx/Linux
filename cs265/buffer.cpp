#include<iostream>
#include"buffer.h"

using namespace std;

VAL_t *Buffer::get(KEY_t key)const{
    entry search_entry;
    set<entry>::iterator entry;
    VAL_t *val;

    search_entry,key = key;
    entry = entries.find(search_entry);

    if(entry == entries.end()){
        return nullptr;
    }else{
        val = new VAL_t;
        *val = entry->val;
        return val;
    }
}

vector<entry>* Buffer::range(KEY_t start,KEY_t end)const{
    entry search_entry;
    set<entry>::iterator subrange_start,subrange_end;

    search_entry.key = start;
    subrange_start = entries.lower_bound(search_entry);

    search_entry.key = end;
    subrange_end = entries.upper_bound(search_entry);

    return new vector<entry>(subrange_start,subrange_end);
}

bool Buffer::put(KEY_t key,VAL_t val){
    entry etry;
    set<entry>::iterator it;
    bool found;

    if(entries.size() == max_size){
        return false;
    }else{
        etry.key = key;
        etry.val = val;

        tie(it,found) = entries.insert(etry);

        if(!found){
            entries.erase(it);
            entries.insert(etry);
        }
        return true;
    }
}

void Buffer::empty(){
    entries.clear();
}