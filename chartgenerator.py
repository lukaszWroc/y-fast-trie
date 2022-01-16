import matplotlib.pyplot as plt
import os
import numpy as np

def createchart(x, y, xs, xe, ys, ye, xl, yl, t, f):
  plt.plot(x, y, color='green', linestyle='dashed', linewidth = 3,
    marker='o', markerfacecolor='blue', markersize=12)

  plt.ylim(ys, ye)
  plt.xlim(xs, xe)

  plt.xlabel(xl)
  plt.ylabel(yl)

  plt.title(t)
  plt.savefig(f)

def main():
  x = []
  y = []
  universum = 2 ** 32
  dateInputNumber = 100000
  questionInputNumber = 100000
  result_time_file = "./build/result_tmp"

  res_min = 1000000.0
  res_max = -1

  os.system("./build/testgenerator data " + str(dateInputNumber) + " " + str(universum) + " > ./build/data.in")
  os.system("./build/testgenerator questions " + str(questionInputNumber) + " " + str(universum) + " > ./build/questions.in")

  start               = -100
  end                 = 400
  p_per_iteration     = 100
  iterations_per_case = 1
  tests               = 1

  itr = start

  while itr <= end:
    state = itr
    itr = itr + p_per_iteration
    result_time_m = 0.0

    for d in range(iterations_per_case):
      os.system("./build/tester --xfasttrie ./build/data.in ./build/questions.in ./build/run_output.out " + str(universum) 
        + " " + str(state) + " > " + result_time_file)

      datafil = open(result_time_file,'r')
      result_time = float(datafil.readline())

      result_time_m += result_time

    x.append(state)
    y.append(result_time_m/iterations_per_case)

    if res_min > result_time_m/iterations_per_case:
      res_min = result_time_m/iterations_per_case

    if res_max < result_time_m/iterations_per_case:
      res_max = result_time_m/iterations_per_case

  for k in range(tests):
    os.system("./build/testgenerator data " + str(dateInputNumber) + " " + str(universum) + " > ./build/data.in")
    os.system("./build/testgenerator questions " + str(questionInputNumber) + " " + str(universum) + " > ./build/questions.in")

    itr = start
    cnt = 0

    while itr <= end:
      state = itr
      itr = itr + p_per_iteration
      result_time_m = 0.0

      for d in range(iterations_per_case):
        os.system("./build/tester --xfasttrie ./build/data.in ./build/questions.in ./build/run_output.out " + str(universum)
          + " " + str(state) + " > " + result_time_file)

        datafil = open(result_time_file,'r')
        result_time = float(datafil.readline())

        result_time_m += result_time

      y[cnt] = y[cnt] + (result_time_m/iterations_per_case)
      cnt = cnt + 1

      if res_min > result_time_m/iterations_per_case:
        res_min = result_time_m/iterations_per_case

      if res_max < result_time_m/iterations_per_case:
        res_max = result_time_m/iterations_per_case

  for k in range(cnt):
    print(y[k])
    y[k] = y[k]/(tests + 1)

  createchart(x,y,start,end,res_min,res_max, "change in bucket size in %", "time (ms)", "How bucket size is affecting efficiency of y fast tire", "./build/testowanko.png")

main()