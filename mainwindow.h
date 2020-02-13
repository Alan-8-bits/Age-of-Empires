#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "civilizacion.h"
#include "videogame.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_guardar_nom_clicked();

    void on_primera_civ_clicked();

    void on_ultima_civ_clicked();

    void on_ordenar_clicked();

    void on_resumen_clicked();

    void on_agregar_clicked();

    void on_inicializar_clicked();

    void on_eliminar_clicked();

    void on_Buscar_clicked();

    void on_agr_ini_clicked();

    void on_agr_fin_clicked();

    void on_eliminar_ald_nom_clicked();

    void on_eliminar_ald_sal_clicked();

    void on_eliminar_ald_eda_clicked();

    void on_ord_ald_nom_clicked();

    void on_ord_ald_eda_clicked();

    void on_ord_ald_sal_clicked();

    void on_actualizar_tabla_clicked();

private:
private:
    Ui::MainWindow *ui;

    VideoGame menu;
    Civilizacion civilizacion;
};

#endif // MAINWINDOW_H
