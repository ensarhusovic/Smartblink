#ifndef GPIO_H
#define GPIO_H

// HUSOVIC GPIO:H

#include <QObject>

const QList<int> LEDS = {18, 23, 24, 25};


const int LFLAGS = 0;


const int CHIP = 0;

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr);
    ~Gpio(); // Hier befindet sich der Destructor


            void set(int pin,bool value);
            void set(unsigned int pattern);



signals:

public slots:
private:
    int m_handle;




};

#endif // HUSOVIC GPIO_H
