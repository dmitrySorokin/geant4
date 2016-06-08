//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef AIDA_ITREE_H
#define AIDA_ITREE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt 

#include <iostream>
#include <string>
#include <vector>

namespace AIDA {

class IManagedObject;

/**
 * User level interface to a Tree.
 *
 * All paths follow unix convention .., ., /, 
 * backslash is the escape character.
 * Relative paths are allowed.
 *
 * NOTE: - this tree keeps a current position(pwd) within the tree.
 * This may be implemented on a per-thread basis.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class ITree {

public: 
    /// Destructor.
    virtual ~ITree() { /* nop */; }

  /**
   * Get the name of the store.
   * @return The store's name.
   *
   */
    virtual const std::string & storeName() const = 0;

  /**
   * Get the IManagedObject at a given path in the ITree. The path can either be
   * absolute or relative to the current working directory.
   * @param path The path.
   * @return     The corresponding IManagedObject.
   *
   */
    virtual IManagedObject * find(const std::string & path) = 0;

  /**
   * Change to a given directory.
   * @param path The absolute or relative path of the directory we are changing to.
   * @return false If the path does not exist.
   *
   */
    virtual bool cd(const std::string & path) = 0;

  /**
   * Get the path of the current working directory.
   * @return The path of the current working directory.
   *
   */
    virtual const std::string & pwd() const = 0;

  /** 
   * List, into a given output stream, all the IManagedObjects, including directories
   * (but not "." and ".."), in a given path. Directories end with "/". The list can be recursive.
   * @param path      The path where the list has to be performed (by default the current directory ".").
   * @param recursive If <code>true</code> the list is extended recursively
   *                  in all the directories under path (the default is <code>false</code>.
   * @param os        The output stream into which the list is dumped (by default the standard output).
   * @return false If the path does not exist.
   *
   */
    virtual bool ls(const std::string & path = ".", bool recursive = false, std::ostream & os = std::cout) const = 0;

  /**
   * Get the list of names of the IManagedObjects under a given path, including directories
   * (but not "." and ".."). Directories end with "/".
   * The returned names are appended to the given path unless the latter is ".".
   * @param path      The path where the list has to be performed (by default the current directory ".").
   * @param recursive If <code>true</code> the list is extended recursively
   *                  in all the directories under path (the default is <code>false</code>.
   *
   */
    virtual std::vector<std::string>  listObjectNames(const std::string & path = ".", bool recursive = false) const = 0;

  /**
   * Get the list of types of the IManagedObjects under a given path.
   * The types are the leaf class of the Interface, e.g. "IHistogram1D", "ITuple", etc.
   * Directories are marked with "dir".
   * The order of the types is the same as the order for the listObjectNames() method
   * to achieve a one-to-one correspondance between object names and types.
   * @param path      The path where the list has to be performed (by default the current directory ".").
   * @param recursive If <code>true</code> the list is extended recursively
   *                  in all the directories under path (the default is <code>false</code>.
   *
   */
    virtual std::vector<std::string>  listObjectTypes(const std::string & path = ".", bool recursive = false) const = 0;

  /**
   * Create a new directory. Given a path only the last directory
   * in it is created if all the intermediate subdirectories already exist.
   * @param path The absolute or relative path of the new directory.
   * @return false If a subdirectory within the path does
   *             not exist or it is not a directory. Also if the directory already exists.
   *
   */   
    virtual bool mkdir(const std::string & path) = 0;

  /**
   * Create a directory recursively. Given a path the last directory
   * and all the intermediate non-existing subdirectories are created.
   * @param path The absolute or relative path of the new directory.
   * @return false If an intermediate subdirectory
   *             is not a directory, or if the directory already exists.
   *
   */
    virtual bool mkdirs(const std::string & path) = 0;

  /**
   * Remove a directory and all the contents underneeth.
   * @param path The absolute or relative path of the directory to be removed.
   * @return false If path does not exist or if it is not
   *             a directory.
   *
   */
    virtual bool rmdir(const std::string & path) = 0;

  /**
   * Remove an IManagedObject by specifying its path.
   * If the path points to a mount point, the mount point should first commit, then 
   * close and delete the tree object.
   * @param path The absolute or relative path of the IManagedObject to be removed.
   * @return false If path does not exist.
   *
   */
    virtual bool rm(const std::string & path) = 0;

  /**
   * Get the full path of an IManagedObject.
   * @param object The IManagedObject whose path is to be returned.
   * @return       The object's absolute path.
   *               In C++ if the object does not exist, an empty string is returned.
   *
   */
    virtual std::string findPath(const IManagedObject & object) const = 0;

  /**
   * Move an IManagedObject or a directory from one directory to another.
   * @param oldPath The path of the IManagedObject or direcoty to be moved.
   * @param newPath The path of the diretory in which the object has to be moved to.
   * @return false If either path does not exist.
   *
   */
    virtual bool mv(const std::string & oldPath, const std::string & newPath) = 0;

  /**
   * Commit any open transaction to the underlying store(s).
   * It flushes objects into the disk for non-memory-mapped stores.
   * @return false If the underlying store cannot be written out.
   *
   */
    virtual bool commit() = 0;

  /**
   * Set the strategy of what should happen if two objects have the same path.
   * Default is overwrite.
   * @param overwrite <code>true</code> to enable overwriting.
   *
   */
    virtual void setOverwrite(bool overwrite = true) = 0;

  /**
   * Copy an object from a path to another.
   * @param oldPath   The path of the object to be copied.
   * @param newPath   The path where the object is to be copied.
   * @param recursive <code>true</code> if a recursive copy has to be performed.
   * @return false If either path does not exist.
   *
   */
    virtual bool cp(const std::string & oldPath, const std::string & newPath, bool recursive = false) = 0;

  /**
   * Create a symbolic link to an object in the ITree.
   * @param path  The absolute or relative path of the object to be linked.
   * @param alias The absolute or relative name of the link.
   * @return false If path or any
   *              subidrectory within path does not exist.
   *
   */
    virtual bool symlink(const std::string & path, const std::string & alias) = 0;

  /**
   * Mounts a tree within another (target) tree. A tree can only be mounted once.
   * Example:
   * <pre>
   *     target.mount("/home/tonyj",tree,"/");
   * </pre>
   * @param path     The path in the target tree
   * @param tree     The tree to mount within the target tree
   * @param treePath The mount point within the tree to be mounted.
   * @return false If something does not exist.
   *
   */
    virtual bool mount(const std::string & path, ITree & tree, const std::string & treePath) = 0;

  /**
   * Unmount a subtree at a given path (mount point).
   * Whenever a tree is destroyed it first unmounts all dependent trees.
   * @param path The path of the subtree to be unmounted.
   * @return false If path does not exist.
   *
   */
    virtual bool unmount(const std::string & path) = 0;

  /**
   * Closes the underlying store.
   * Changes will be saved only if commit() has been called before.
   * The call is propagated to the dependent mounted trees.
   * @return false If there are problems writing out
   *         the underlying store.
   *
   */
    virtual bool close() = 0;
}; // class
}; // namespace AIDA
#endif /* ifndef AIDA_ITREE_H */