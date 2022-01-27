#include "gui.h"


// HUSOVIC GUI.H

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
        setupUi(this);
        m_x_LEDs = new Gpio(this);

        m_z_MOMENT = 0;

        m_y_TIMER = new QTimer();

        connect(m_y_TIMER, &QTimer::timeout, this, &Gui::toggle); // HIER findet die Verbindung zum Timer statt

        m_y_TIMER->start(TIMEOUT);
}



void Gui::on_speedSlider_valueChanged(int value)
{
    m_y_TIMER->start(1000/value);
}



void Gui::on_blinkButton_clicked()
{
    m_a_BLINK_oder_LAUF = 1;
}



void Gui::on_lauflichtButton_clicked()
{
    m_a_BLINK_oder_LAUF = 0;
    ZAEHLER = 1;
}

    void Gui::toggle()
    {
        m_z_MOMENT = !m_z_MOMENT;
        if(m_a_BLINK_oder_LAUF == 1)
        {
                if(m_z_MOMENT == 1)
                {
                    ZAEHLER = 15;
                }else {
                    ZAEHLER = 0;
                }
                m_x_LEDs->set(ZAEHLER);
        }
        if(m_a_BLINK_oder_LAUF == 0)
        {
            m_x_LEDs->set(ZAEHLER);

                if(ZAEHLER < 8)
                {
                    ZAEHLER = ZAEHLER * 2;
                }


                else {
                    ZAEHLER = 1;
                }
    }
}
