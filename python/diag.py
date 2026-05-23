from graphviz import Digraph

# Create a new directed graph
dfd = Digraph('DFD', node_attr={'shape': 'circle', 'fontsize': '12', 'fixedsize': 'true', 'width': '1'})

# External entities
dfd.node('Customer', shape='rectangle')
dfd.node('Supplier', shape='rectangle')

# Processes
dfd.node('P1', 'Order Processing')
dfd.node('P2', 'Inventory Management')

# Data Stores
dfd.node('D1', 'Orders', shape='ellipse')
dfd.node('D2', 'Inventory', shape='ellipse')

# Data Flows
dfd.edge('Customer', 'P1', label='Order')
dfd.edge('P1', 'D1', label='Order Details')
dfd.edge('D1', 'P2', label='Order Information')
dfd.edge('P2', 'D2', label='Update Inventory')
dfd.edge('D2', 'P2', label='Inventory Status')
dfd.edge('P2', 'Supplier', label='Order Supplies')
dfd.edge('Supplier', 'P2', label='Supplies')

# Render the DFD to a file
dfd.render('dfd-example', format='png', view=True)
