#include "win2kstyle.h"
#include <QStyleFactory>
#include <QPainter>
#include <QStyleOptionButton>

Win2kStyle::Win2kStyle(QStyle *base)
    : QProxyStyle(base ? base : QStyleFactory::create("Windows"))
{
}

QPalette Win2kStyle::standardPalette() const {
    QPalette palette;
    QColor bg("#d4d0c8");  // Classic Windows 2000 background
    QColor btn("#f0f0f0");
    QColor frame("#808080");
    QColor highlight("#0a246a");
    QColor text("#000000");

    palette.setColor(QPalette::Window, bg);
    palette.setColor(QPalette::Button, btn);
    palette.setColor(QPalette::ButtonText, text);
    palette.setColor(QPalette::Base, QColor("#ffffff"));
    palette.setColor(QPalette::Highlight, highlight);
    palette.setColor(QPalette::HighlightedText, QColor("#ffffff"));
    palette.setColor(QPalette::Mid, frame);

    return palette;
}

void Win2kStyle::drawControl(ControlElement element, const QStyleOption *option,
                             QPainter *painter, const QWidget *widget) const
{
    if (element == CE_PushButton) {
        const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(option);
        if (btn) {
            bool sunken = btn->state & State_Sunken || btn->state & State_On;
            QRect r = btn->rect;
            QColor light("#ffffff"), dark("#808080"), mid("#c0c0c0");

            painter->fillRect(r, QColor("#f0f0f0"));
            painter->setPen(sunken ? dark : light);
            painter->drawLine(r.topLeft(), r.topRight());
            painter->drawLine(r.topLeft(), r.bottomLeft());

            painter->setPen(sunken ? light : dark);
            painter->drawLine(r.bottomLeft(), r.bottomRight());
            painter->drawLine(r.topRight(), r.bottomRight());

            QRect textRect = subElementRect(SE_PushButtonContents, btn, widget);
            drawItemText(painter, textRect, Qt::AlignCenter, btn->palette, true, btn->text);
            return;
        }
    }

    QProxyStyle::drawControl(element, option, painter, widget);
}

