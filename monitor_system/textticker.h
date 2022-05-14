#ifndef TEXTTICKER_H
#define TEXTTICKER_H

#include <QObject>
#include <QtWidgets/QLabel>

class TextTicker : public QLabel
{
    Q_OBJECT
public:
    TextTicker(QWidget *parent = 0);
    void setText(QString text);
    ~TextTicker();
protected:
    void paintEvent(QPaintEvent *event);
    void updateIndex();

private:
    int m_charWidth;
    int m_curIndex;
    QString m_showText;

};

#endif // TEXTTICKER_H
