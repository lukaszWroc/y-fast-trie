import matplotlib.pyplot as plt
import os
import numpy as np

def createchart(x, y, xs, xe, ys, ye, xl, yl, t, f, label1, x2, y2, label2):
  plt.plot(x, y, color='blue', linestyle='dashed', linewidth = 3,
    marker='o', markerfacecolor='blue', markersize=12, label = label1)

  plt.ylim(ys, ye+5)
  plt.xlim(xs, xe)

  plt.xlabel(xl)
  plt.ylabel(yl)

  plt.plot(x2, y2, color='red', linestyle='dashed', linewidth = 3,
    marker='o', markerfacecolor='red', markersize=12, label = label2)

  plt.legend()

  plt.title(t)
  plt.savefig(f)


def main():
  universum = 2 ** 30
  dateInputNumber = 15000000
  questionInputNumber = 20000000
  result_time_file = "./build/result_tmp"

  res_min = 10000000.0
  res_max = -1

  os.system("./build/testgenerator data " + str(dateInputNumber) + " " + str(universum) + " > ./build/data.in")
  os.system("./build/testgenerator questions " + str(questionInputNumber) + " " + str(universum) + " > ./build/questions.in")

  start               = -50
  end                 = 500
  p_per_iteration     = 100
  iterations_per_case = 1
  tests               = 1

  itr = start
  tmp = 0
  while itr <= end:
    itr = itr + p_per_iteration
    tmp = tmp + 1

  x = np.empty(tmp, float)
  y = np.empty(tmp, float)
  x2 = np.empty(tmp, float)
  y2 = np.empty(tmp, float)

  itr = start

  for k in range(tests):
    os.system("./build/testgenerator data " + str(dateInputNumber) + " " + str(universum) + " > ./build/data.in")
    os.system("./build/testgenerator questions " + str(questionInputNumber) + " " + str(universum) + " > ./build/questions.in")

    itr = start
    cnt = 0

    while itr <= end:
      state = itr
      itr = itr + p_per_iteration
      result_time_m = 0.0
      x[cnt] = state
      x2[cnt] = state

      for d in range(iterations_per_case):
        os.system("./build/tester --yfasttrie ./build/data.in ./build/questions.in ./build/run_output.out " + str(universum)
          + " " + str(state) + " > " + result_time_file)

        datafil = open(result_time_file,'r')
        result_time = float(datafil.readline())

        result_time_m += result_time

      y[cnt] = y[cnt] + (result_time_m/iterations_per_case)

      if res_min > result_time_m/iterations_per_case:
        res_min = result_time_m/iterations_per_case

      if res_max < result_time_m/iterations_per_case:
        res_max = result_time_m/iterations_per_case

      result_time_m = 0.0

      for d in range(iterations_per_case):
        os.system("./build/tester --bst ./build/data.in ./build/questions.in ./build/run_output.out " + str(universum)
          + " " + str(state) + " > " + result_time_file)

        datafil = open(result_time_file,'r')
        result_time = float(datafil.readline())

        result_time_m += result_time

      y2[cnt] = y2[cnt] + (result_time_m/iterations_per_case)
      cnt = cnt + 1

      if res_min > result_time_m/iterations_per_case:
        res_min = result_time_m/iterations_per_case

      if res_max < result_time_m/iterations_per_case:
        res_max = result_time_m/iterations_per_case

  for k in range(cnt):
    print(y[k])
    print(y2[k])

    y[k] = y[k]/tests
    y2[k] = y2[k]/tests


  createchart(x,y,start,end,res_min,res_max, "change in bucket size in %", "time (ms)", "How bucket size is affecting efficiency of y fast tire", "./build/chart.png", "yfast", x2, y2, "bst")

main()