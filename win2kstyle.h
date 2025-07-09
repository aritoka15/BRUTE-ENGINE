#ifndef WIN2KSTYLE_H
#define WIN2KSTYLE_H

#include <QProxyStyle>

class Win2kStyle : public QProxyStyle {
public:
    Win2kStyle(QStyle *base = nullptr);

    QPalette standardPalette() const override;
    void drawControl(ControlElement element, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget = nullptr) const override;
};

#endif // WIN2KSTYLE_H
