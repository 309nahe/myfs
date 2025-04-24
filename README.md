# myfs

## Simple File System Implementation in C

This project aims to implement a basic file system in C. The file system will support fundamental file operations such as creating, reading, and deleting files. The implementation will initially focus on an in-memory file system and later extend to persistent storage.

## Project Structure

The project will be organized into the following components:

- **Data Structures**: Definitions for files and the file system.
- **API Functions**: Functions to create, read, and delete files.

## Step-by-Step Implementation

### Step 1: Define Data Structures and basic file handling

**Objective**: Create the basic data structures for files and the file system.

**Tasks**:
- Define a `File` struct to hold file metadata and content.
- Define a `FileSystem` struct to manage a collection of files.
- Create the basic functions to handle a flat filesystem in memory such as : create_file, delete_file
