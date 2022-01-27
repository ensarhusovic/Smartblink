#ifndef GUI_H
#define GUI_H
#include <QWidget>
#include "ui_gui.h"
#include "gpio.h"
#include <QTimer>

//HUSOVIC GUI

const int TIMEOUT = 1000;

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);

private slots:
        void on_speedSlider_valueChanged(int value);

        void on_blinkButton_clicked();

        void on_lauflichtButton_clicked();

        void toggle();


private:
        QTimer* m_y_TIMER;

        bool m_z_MOMENT = 0;

        bool m_a_BLINK_oder_LAUF = 1;

        unsigned int ZAEHLER = 1;

        Gpio* m_x_LEDs;
};

#endif // HUSOVIC GUI_H
