#pragma once

#include <iostream>
#include <vector>

/*
الكتلة: هي الجزء الاكبر وهي الذاكرة الافتراضية نفسها
القطعة: هي الجزء الذي يتم حجزه وهنا يكون بحجم 8192 بايت ويتم إسناد عنوان اول بايت فيها في متغير segments_
واول اربعة بايت فيها مخصصة لعد الوحدات
الوحدة: هي الكمية المحجوزة في القطعة سواء كانت 64 بايت او اكثر او اقل
*/


class MemoryBlock {
private:
    std::vector<char*> segments_;
    char* currentSegment;
    size_t segmentSize;
    size_t currentIndex;
    int* fragmentCounts;

public:
    MemoryBlock(size_t _segmentSize = 8192);

    void* allocate(size_t);
    void deallocate(void*);
};
