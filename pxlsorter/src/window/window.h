#ifndef WINDOW_H1
#define WINDOW_H1
/* #include "ui_window.h" */

#include <QMainWindow>
#include <QFileDialog>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QDragEnterEvents>
#include <QMessageBox>

namespace UI {
  class Main;
}

class Main : public QMainWindow {
  Q_OBJECT

public:
    explicit Window(QWidget *par = 0);
    ~Main();

}
#endif //WINDOW_H1
