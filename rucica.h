#ifndef __RUCICA_H__
#define __RUCICA_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

/* Standart GObject macros */
#define PANED_RUCICA_TYPE (paned_rucica_get_type())
#define PANED_RUCICA(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), PANED_RUCICA_TYPE, PanedRucica))// proverava i kastuje zadati objekat(obj) po tipu PanedRucica
#define PANED_RUCICA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), PANED_RUCICA_TYPE, PanedRucicaClass))// po klasi
#define PANED_IS_RUCICA(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), PANED_RUCICA_TYPE))
#define PANED_IS_RUCICA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), PANED_RUCICA_TYPE))
#define PANED_RUCICA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), PANED_RUCICA_TYPE, PanedRucicaClass))

/* Type definition */
typedef struct _PanedRucica        PanedRucica;
typedef struct _PanedRucicaClass   PanedRucicaClass;
typedef struct _PanedRucicaPrivate PanedRucicaPrivate;

struct _PanedRucica{
	
	GtkWidget parent;
	
	PanedRucicaPrivate;
	
};

struct _PanedRucicaClass{
	
	GtkWidgetClass parrent_class;
	
};

GType      my_cpu_get_type(void) G_GNUC_CONST;
GtkWidget *my_cpu_new(void);

G_END_DECLS

#endif __RUCICA_H__


// PRVO DEFINISATI TIP, DEFINSANJE TIPA DODELJUJE NOVI TIP, PRAVI DEKLARACIJE I DEFINICIJE FUNKCIJA INICIJALIZACIJE
// (NEKE DEFINICIJE KORISNIK MORA DA DODA), KADA JE DOBIJEN NOVI TIP PISE SE FUNKCIJA ZA DODELJIVANJE POINTERA NA OBJEKAT KOJI JE TIPA 
// NOVOG DOBIJENOG TIPA (DOBIJENOG KORISCENJEM MACROA G_DEFINE_TYPE(cAmile, with_underscore, parrent gtype)) nakon svega imamo 
// inicijalizovan objekat, svim strukturama varijablama i pointerima dodeljene su vrednosti zadate u init i class_init funkcijama
// postoje i virtualne funkcije preko kojih se pisu funkcije specificne za novonastali objekat
// CLASS INIT FUNKCIJA DODELJUJE METODE(FUNKCIJE) KLASI OBJEKTA
// INIT FUNKCIJA INICIJALIZUJE PRIVATNE I JAVNE ELEMENTE KREIRANOG OBJEKTA/INSTANCE(KONSTRUKTOR) (INICIJALIZACIJA KLASE I INICIJALIZACIJE INSTANCE)

