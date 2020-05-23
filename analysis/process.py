#!/bin/python

import json

max_cost = 0

with open('result.txt', 'r') as f:
    for line in f.readlines():
        # print line
        json_object = json.loads(line)
        # print json_object["total_cost"]
        total_cost = int(json_object["total_cost"])
        print total_cost
        if total_cost > max_cost:
            max_cost = total_cost

print "max_cost:"
print max_cost
