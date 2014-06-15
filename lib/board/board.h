#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QVector>

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(int size = 11, QObject *parent = 0);

    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int colors READ colors WRITE setColors NOTIFY colorsChanged)
    Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(int selected READ selected WRITE setSelected NOTIFY selectedChanged)

    void setScore(int value){
        _score = value;
        emit scoreChanged(value);
    }

    void setColors(int value){
        _colors = value;
        emit colorsChanged(value);
    }

    void setSize(int value){
        _size = value;
        emit sizeChanged(value);
    }

    void setSelected(int value){
        _selected = value;
        emit selectedChanged(value);
    }

    int score() const { return _score; }
    int colors() const { return _colors; }
    int size() const { return _size; }
    int selected() const { return _selected; }

    void generateRandom();
    Q_INVOKABLE QVector<QVector<int> > getMatrix(){ return _matrix; }

signals:
    void scoreChanged(int);
    void colorsChanged(int);
    void sizeChanged(int);
    void selectedChanged(int);

public slots:

private:
    typedef QVector<QVector<int> > Matrix;
    Matrix _matrix;

    int _score;
    int _colors;
    int _size;
    int _selected;
};

#endif // BOARD_H
