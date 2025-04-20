# Hypergraph-TC

# 📊 Dataset Format & Execution Guide

This repository contains two input files, `degree.txt` and `edges.txt`, describing a hypergraph dataset, along with a C++ program for processing the data. This document explains the file formats and provides instructions on compiling and running the code.

---

## 📄 File: `degree.txt`

This file contains metadata and the degree of each node in the graph.

### Format

<num_nodes> <num_edges> <num_all_data>
<deg_1>
<deg_2>
...
<deg_n>


## 📄 File: `edges.txt`

This file contains metadata and the degree of each node in the graph.

### Format

<node_id_1> <node_id_2> [<node_id_3> ...]

## ⚙️ Compilation and Execution

The provided C++ implementation supports flexible and efficient processing of these datasets.

### Step 1: Compile

Ensure you are using a compiler that supports C++17. Run the following command:

g++ -std=c++17 -o main *.cpp -O3


### Step 2: Run

./main <file_path_prefix> <sample_size> <tau>

