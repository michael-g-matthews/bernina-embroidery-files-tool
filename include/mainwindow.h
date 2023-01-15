#ifndef MGMATTHEWS_MAINWINDOW_H
#define MGMATTHEWS_MAINWINDOW_H

#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:

    // Source label
    QLabel *src_label;
    // Source text box (allow drag and drop?)
    QComboBox *src_cbox;
    // Source Browse button
    QPushButton *src_btn;
    QDir src_dir;

    // Destination label
    QLabel *dest_label;
    // Destination text box (allow drag and drop?)
    QComboBox *dest_cbox;
    // Destination Browse button
    QPushButton *dest_btn;
    QDir dest_dir;

    // Fun image of file transfer
    // Run button
    QPushButton *run_btn;

    // Progress bar

};


#endif // MGMATTHEWS_MAINWINDOW_H