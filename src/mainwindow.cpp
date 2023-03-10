#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QDialog(parent) {
    setWindowTitle("File Mover Tool for Bernina Embroidery Machines");

    // Create components
    src_label = new QLabel("Source Folder", this);
    src_cbox = new QComboBox(this);
    src_cbox->setEditable(true);
    src_cbox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    src_cbox->addItem(QDir::toNativeSeparators(QDir::homePath()));
    src_btn = new QPushButton("Browse...",this);
    src_files_table = new QTableWidget(0,3, this);
    src_files_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    src_files_table->setHorizontalHeaderLabels({"Name", "Date Modified", "Size"});
    src_files_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    src_files_table->verticalHeader()->hide();
    src_files_table->setShowGrid(false);
    src_files_table->setSortingEnabled(true);


    dest_label = new QLabel("Destination Folder", this);
    dest_cbox = new QComboBox(this);
    dest_cbox->setEditable(true);
    dest_cbox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    dest_btn = new QPushButton("Browse...",this);

    move_btn = new QPushButton("Move", this);
    move_btn->setAutoDefault(true);
    move_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Create Layout
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    QHBoxLayout *src_label_row = new QHBoxLayout();
    QHBoxLayout *src_selection_row = new QHBoxLayout();
    QHBoxLayout *dest_label_row = new QHBoxLayout();
    QHBoxLayout *dest_selection_row = new QHBoxLayout();
    QHBoxLayout *action_row = new QHBoxLayout();

    vlayout->addLayout(src_label_row);
    src_label_row->addWidget(src_label);
    src_label_row->addStretch();
    vlayout->addLayout(src_selection_row);
    src_selection_row->addWidget(src_cbox);
    src_selection_row->addWidget(src_btn);
    vlayout->addWidget(src_files_table);
    vlayout->addLayout(dest_label_row);
    dest_label_row->addWidget(dest_label);
    dest_label_row->addStretch();
    vlayout->addLayout(dest_selection_row);
    dest_selection_row->addWidget(dest_cbox);
    dest_selection_row->addWidget(dest_btn);
    vlayout->addLayout(action_row);
    action_row->addStretch();
    action_row->addWidget(move_btn);
    action_row->addStretch();

    // Bind functionality to components
    connect(new QShortcut(QKeySequence::Quit, this), &QShortcut::activated, qApp, &QApplication::quit);
    connect(new QShortcut(QKeySequence::Close, this), &QShortcut::activated, qApp, &QApplication::quit);

    connect(src_btn, &QAbstractButton::clicked, this, &MainWindow::browseSrcDir);

    connect(dest_btn, &QAbstractButton::clicked, this, &MainWindow::browseDestDir);

}

MainWindow::~MainWindow() {
    qDebug() << "Destroying Main Window at addr: " << this;
    // delete objects
    // objects are deleted automatically via Qt parent-child QObject relationship
}

void MainWindow::browseSrcDir() {
    browse("Source", src_cbox);
}

void MainWindow::browseDestDir() {
    browse("Destination", dest_cbox);
}

void MainWindow::browse(const QString &choice, QComboBox *component) {
    QString current_dir = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, "Select "+ choice +" Folder", QDir::currentPath()));
    if (!current_dir.isEmpty()) {
        if (component->findText(current_dir) == -1) {
            component->addItem(current_dir);
        }
        component->setCurrentIndex(component->findText(current_dir));
    }
}
