#ifndef RGBCOLOR_H
#define RGBCOLOR_H

namespace bricks {
class RGBColor {
public:
    RGBColor(int r, int g, int b, int a = 0xFF);

    int r() const;
    int g() const;
    int b() const;
    int a() const;

    RGBColor lighter(double factor) const;
    RGBColor darker(double factor) const;

private:
    int calcLighterPart(int part, double factor = 0.3) const;
    int calcDarkerPart(int part, double factor = 0.3) const;

    const int mR;
    const int mG;
    const int mB;
    const int mA;
};
} // namespace bricks
#endif