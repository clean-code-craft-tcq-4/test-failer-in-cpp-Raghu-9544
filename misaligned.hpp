#ifndef MISALIGNED_HPP
#define MISALIGNED_HPP

namespace TelCoColorCoder
{
    enum WIRE_MAJOR_COLOR
    {
        WHITE,RED,BLACK,YELLOW,VIOLET
    };
    enum WIRE_MINOR_COLOR
    {
        BLUE,ORANGE,GREEN,BROWN,SLATE
    };

    class ColorCode
    {
        public:
        
        const char*   m_majorColor;
        const char*   m_minorColor;
        int           m_pairNumber;

        char const* getMinorColor() const;
        char const* getMajorColor() const;
        int   getPairNumber() const;

    };
    //extern ColorCode* ColorCodeDatabase[25];
    extern const char* majorColor[];
    extern const char* minorColor[];

    int printColorCodeManual(ColorCode* ColorCodeDatabase[]);
    void createColorCodeManual(const char* majorColor[], const char* minorColor[], ColorCode* ColorCodeDatabase[]);

}    
#endif
