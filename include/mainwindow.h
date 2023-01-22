#ifndef MGMATTHEWS_MAINWINDOW_H
#define MGMATTHEWS_MAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QBoxLayout>
#include <QHeaderView>

#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QShortcut>
#include <QApplication>





class MainWindow : public QDialog {
    //Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void browseSrcDir(); 
    void browseDestDir();


private:

    QLabel *src_label; // Source label
    QComboBox *src_cbox; // Source text box (allow drag and drop?)
    QPushButton *src_btn; // Source Browse button
    QDir src_dir; // source directory in filesystem
    QTableWidget* src_files_table; // table showing files in src directory

   
    QLabel *dest_label;  // Destination label
    QComboBox *dest_cbox;  // Destination text box (allow drag and drop?)
    QPushButton *dest_btn; // Destination Browse button
    QDir dest_dir; // destination directory in filesystem

    // One move button or should there be move back and forth so you can select specific patterns. Or possibly a move all, each way?
    QPushButton *move_btn;
    QPushButton *copy_btm;

    void browse(const QString &choice, QComboBox *component);

};


#endif // MGMATTHEWS_MAINWINDOW_H