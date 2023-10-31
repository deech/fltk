//
// Fl_Grid type header file for the Fast Light Tool Kit (FLTK).
//
// Copyright 2023 by Bill Spitzak and others.
//
// This library is free software. Distribution and use rights are outlined in
// the file "COPYING" which should have been included with this file.  If this
// file is missing or damaged, see the license at:
//
//     https://www.fltk.org/COPYING.php
//
// Please see the following page on how to report bugs and issues:
//
//     https://www.fltk.org/bugs.php
//

#ifndef _FLUID_FL_GRID_TYPE_H
#define _FLUID_FL_GRID_TYPE_H

#include "Fl_Group_Type.h"
#include <FL/Fl_Grid.H>

// ---- Fl_Grid_Type --------------------------------------------------- MARK: -

extern const char grid_type_name[];

class Fl_Grid_Proxy : public Fl_Grid {
public:
  Fl_Grid_Proxy(int X,int Y,int W,int H) : Fl_Grid(X,Y,W,H) {}
  void resize(int,int,int,int) FL_OVERRIDE;
};

class Fl_Grid_Type : public Fl_Group_Type
{
  typedef Fl_Group_Type super;
public:
  Fl_Grid_Type();
  const char *type_name() FL_OVERRIDE {return grid_type_name;}
  const char *alt_type_name() FL_OVERRIDE {return "fltk::GridGroup";}
  Fl_Widget_Type *_make() FL_OVERRIDE { return new Fl_Grid_Type(); }
  Fl_Widget *widget(int X,int Y,int W,int H) FL_OVERRIDE;
  ID id() const FL_OVERRIDE { return ID_Grid; }
  bool is_a(ID inID) const FL_OVERRIDE { return (inID==ID_Grid) ? true : super::is_a(inID); }
  void write_properties(Fd_Project_Writer &f) FL_OVERRIDE;
  void read_property(Fd_Project_Reader &f, const char *) FL_OVERRIDE;
  void write_parent_properties(Fd_Project_Writer &f, Fl_Type *child, bool encapsulate) FL_OVERRIDE;
  void read_parent_properties(Fd_Project_Reader &f, Fl_Type *child, const char *property) FL_OVERRIDE;
  void copy_properties() FL_OVERRIDE;
  void write_code1(Fd_Code_Writer& f) FL_OVERRIDE;
  void write_code2(Fd_Code_Writer& f) FL_OVERRIDE;
  void add_child(Fl_Type*, Fl_Type*) FL_OVERRIDE;
  void move_child(Fl_Type*, Fl_Type*) FL_OVERRIDE;
  void remove_child(Fl_Type*) FL_OVERRIDE;
  void layout_widget() FL_OVERRIDE;
  void child_resized(Fl_Widget_Type *child);
  void insert_child_at(Fl_Widget *child, int x, int y);
  void insert_child(Fl_Widget *child);

  static class Fl_Grid *selected();
};

#endif // _FLUID_FL_GRID_TYPE_H
