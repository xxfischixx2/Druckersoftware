#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <QObject>
#include <QUrl>
#include <QSettings>
#include <QTimer>

struct CommandBuffer {

    QStringList buffer;
    QList<ushort> bufferInfo;
};

class MotorController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qreal m_currentXAxisPosition READ currentXAxisPosition WRITE setCurrentXAxisPosition NOTIFY currentXAxisPositionChanged)
    Q_PROPERTY(qreal m_currentYAxisPosition READ currentYAxisPosition WRITE setCurrentYAxisPosition NOTIFY currentYAxisPositionChanged)
    Q_PROPERTY(qreal m_currentZAxisPosition READ currentZAxisPosition WRITE setCurrentZAxisPosition NOTIFY currentZAxisPositionChanged)
    Q_PROPERTY(qreal m_currentExtruderPosition READ currentExtruderPosition WRITE setCurrentExtruderPosition NOTIFY currentExtruderPositionChanged)

public:
    explicit MotorController(QObject *parent = nullptr);
    ~MotorController();

    enum MotorState{Moving, Paused, Stopped, Idle};

    bool xAxisReferenceDrive();
    bool yAxisReferenceDrive();
    bool zAxisReferenceDrive();
    bool absoluteMoveXAxis(qreal position, qreal speed);
    bool relativeMoveXAxis(qreal value, qreal speed);
    bool absoluteMoveYAxis(qreal position, qreal speed);
    bool relativeMoveYAxis(qreal value, qreal speed);
    bool absoluteMoveZAxis(qreal position, qreal speed);
    bool relativeMoveZAxis(qreal value, qreal speed);
    bool absoluteMoveExtruder(qreal position, qreal speed);
    bool relativeMoveExtruder(qreal value, qreal speed);
    bool absoluteMove(qreal x, qreal y, qreal z, qreal e, qreal xSpeed, qreal ySpeed, qreal zSpeed, qreal eSpeed);
    bool relativeMove(qreal x, qreal y, qreal z, qreal e, qreal xSpeed, qreal ySpeed, qreal zSpeed, qreal eSpeed);
    void setXAxisMaxFeedrate(qreal xAxisMaxFeedrate);
    qreal xAxisMaxFeedrate();
    void setYAxisMaxFeedrate(qreal yAxisMaxFeedrate);
    qreal yAxisMaxFeedrate();
    void setZAxisMaxFeedrate(qreal zAxisMaxFeedrate);
    qreal zAxisMaxFeedrate();
    void setExtruderMaxFeedrate(qreal extruderMaxFeedrate);
    qreal extruderMaxFeedrate();
    void setDefaultPrintingAcceleration(qreal defaultPrintingAcceleration);
    qreal defaultPrintingAcceleration();
    void setDefaultTravelAcceleration(qreal defaultTravelAcceleration);
    qreal defaultTravelAcceleration();
    qreal currentXAxisPosition();
    qreal currentYAxisPosition();
    qreal currentZAxisPosition();
    qreal currentExtruderPosition();
    void setCurrentXAxisPosition(qreal currentXAxisPosition);
    void setCurrentYAxisPosition(qreal currentYAxisPosition);
    void setCurrentZAxisPosition(qreal currentZAxisPosition);
    void setCurrentExtruderPosition(qreal currentExtruderPosition);
    int currentXAxisTemp();
    int currentYAxisTemp();
    int currentZAxisTemp();
    int currentExtruderTemp();

signals:

    void error(QString errorMessage);
    void movementFinished();
    void send(QString text);
    void currentXAxisPositionChanged(qreal position);
    void currentYAxisPositionChanged(qreal position);
    void currentZAxisPositionChanged(qreal position);
    void currentExtruderPositionChanged(qreal position);
    void currentXAxisTempChanged(int temp);
    void currentYAxisTempChanged(int temp);
    void currentZAxisTempChanged(int temp);
    void currentExtruderTempChanged(int temp);

public slots:

    void receive(QString text);
    void clear();
    void pause();
    void play();
    void stop();

private slots:

    void checkMovement();
    void checkTemp();

private:

    void motorSetup();
    void calculateMovementChange();
    void checkBuffer();

    MotorState *m_motorState;
    qreal *m_currentXAxisPosition;
    qreal *m_currentYAxisPosition;
    qreal *m_currentZAxisPosition;
    qreal *m_currentExtruderPosition;
    qreal *m_previousXAxisPosition;
    qreal *m_previousYAxisPosition;
    qreal *m_previousZAxisPosition;
    qreal *m_previousExtruderPosition;
    qint32 *m_currentXAxisMotorPosition;
    qint32 *m_currentYAxisMotorPosition;
    qint32 *m_currentZAxisMotorPosition;
    qint32 *m_currentExtruderMotorPosition;
    qint32 *m_desiredXAxisMotorPosition;
    qint32 *m_desiredYAxisMotorPosition;
    qint32 *m_desiredZAxisMotorPosition;
    qint32 *m_desiredExtruderMotorPosition;
    int *m_currentXAxisTemp;
    int *m_currentYAxisTemp;
    int *m_currentZAxisTemp;
    int *m_currentExtruderTemp;
    CommandBuffer *m_commandBuffer;
    QSettings *m_settings;
};

#endif // MOTORCONTROLLER_H
